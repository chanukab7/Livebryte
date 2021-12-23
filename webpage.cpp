#include "webpage.h"

String homepage() PROGMEM{
String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
      <style>
        .center {
          margin: auto;
          text-align: center;
        }

        .img {
          display:block;
          margin-left: auto;
          margin-right: auto;
        }

        .button {
          background-color: #91d6ec; /* Blue */
          padding: auto;
          font-size: large;
          
        } 

        </style>

        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Homepage</title>
    </head>
    <body><header><div>
            <div>
              <div>
                <img src="https://upload.wikimedia.org/wikipedia/en/2/23/Kotelawala_Defence_University_crest.png" class="img" style="width:256px;"><br>
                <h1 class="center">GENERAL SIR JOHN KOTELAWALA DEFENCE UNIVERSITY</h1><br>
                <p><img src="https://i.ibb.co/KrrWctB/livebryte.png" class="img" alt="livebryte" style="width:150px;"></p>
                
              </div>
            </div>
          </div>
    </header>
    <div class="center">
      <h2>Project of B. M. C. D. Bandara</h2>
      <p>Induvidual Design Project - Intake 37,<br>Deparment of Electrical, Electronic and Telecommunication Engineering,<br>Faculty of Engineering,<br>General Sir John Kotelawala Defence University.
      </p>
      <a href="settings"><button class="button" role="button">Continue</button></a>
    </div>
    </body>
</html>
)rawliteral";

return page;
}

String settings() PROGMEM{
String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Settings</title>
        <script src="https://cdn.lordicon.com/libs/mssddfmo/lord-icon-2.1.0.js"></script>
        <style>
            .button {
            background-color: hsl(195, 100%, 80%); /* Blue */
            font-size: large;
            padding-block: 5px;
        }

        </style>
    </head>
    <body>
        <header>
                <img src="https://i.ibb.co/KrrWctB/livebryte.png"  alt="livebryte" style="height:100px;"> 
                <h1>SETTINGS</h1>
        </header>
              <div>
                <a href="/settings/wifi"><button class="button" role="button">WI-FI CONFIGURATION</button></a><br><br>
              </div>
              <div>
                <a href="/settings/timesetting"><button class="button" role="button">TIME SETTING</button></a><br><br>
            </div>
            <div>
                <a href="/settings/phone"><button class="button" role="button">PHONE NUMBER</button></a><br><br>
            </div>
            <div>
                <a href="/settings/choosecompartment"><button class="button" role="button">COMPARTMENT SETTINGS</button></a>
            </div>
            </div>
          </div>
          <div><br><br>
              <a href="/">Return to Homepage</a>
          </div>
    </body>
    <footer>
        <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
    </footer>
</html>

)rawliteral";

return page;
}

String doseChart() PROGMEM{
    String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Dose Chart</title>

        <style>
            .button {
            background-color: hsl(14, 94%, 82%); /* Blue */
            font-size: 20px;
            padding-block: 5px;
            border-radius: 10px;
        }

        </style>   
    </head>
    <body>
        <img src="https://i.ibb.co/KrrWctB/livebryte.png"  alt="livebryte" style="height:100px;"> 
        <header>
            <h1>DOSE CHART</h1>
        </header>
        <div>
            <table>
                <tr>
                    <th>#</th>
                    <th>| Time</th>
                    <th>| Compartment 1</th>
                    <th>| Compartment 2</th>
                    <th>| Compartment 3</th>
                    <th>| Last Dose Dispenced?</th>
                </tr>
                <tr>
                    <th>1</th>
                    <th><!---time--->)rawliteral";

                    Preferences pref;
                    pref.begin("doseslot1", true);

                    page += pref.getString("time");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 1 dose--->)rawliteral";

                    page += pref.getUInt("comp1");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 2 dose--->)rawliteral";
                    page += pref.getUInt("comp2");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 3 dose--->)rawliteral";
                    page += pref.getUInt("comp3");
                    
                    page +=R"rawliteral(</th>
                    <th><!---yes/no--->)rawliteral";
                    page += pref.getString("disposed");

                    pref.end();
                    
                    page +=R"rawliteral(</th>
                </tr>
                <tr>
                    <th>2</th>
                    <th><!---time--->)rawliteral";

                    Preferences pref;
                    pref.begin("doseslot2", true);

                    page += pref.getString("time");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 1 dose--->)rawliteral";

                    page += pref.getUInt("comp1");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 2 dose--->)rawliteral";
                    page += pref.getUInt("comp2");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 3 dose--->)rawliteral";
                    page += pref.getUInt("comp3");
                    
                    page +=R"rawliteral(</th>
                    <th><!---yes/no--->)rawliteral";
                    page += pref.getString("disposed");

                    pref.end();
                    
                    page +=R"rawliteral(</th>
                </tr>
                <tr>
                    <th>3</th>
                    <th><!---time--->)rawliteral";

                    Preferences pref;
                    pref.begin("doseslot3", true);

                    page += pref.getString("time");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 1 dose--->)rawliteral";

                    page += pref.getUInt("comp1");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 2 dose--->)rawliteral";
                    page += pref.getUInt("comp2");
                    
                    page +=R"rawliteral(</th>
                    <th><!---Compartment 3 dose--->)rawliteral";
                    page += pref.getUInt("comp3");
                    
                    page +=R"rawliteral(</th>
                    <th><!---yes/no--->)rawliteral";
                    page += pref.getString("disposed");

                    pref.end();
                    
                    page +=R"rawliteral(</th>
                </tr>
            </table>
        </div>

        <br><div>
            <a href="/dosechart/editdose/"><button class=button>Edit Dose</button></a>
        </div>

        <br><br><div>
            <a href="/settings">Return to Settings</a><br>
            <a href="/">Return to Homepage</a>
        </div>
    </body>
    <footer>
    <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
    </footer>
</html>
})rawliteral";

return page;
}

String editDose() PROGMEM{
    String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Dose</title>

        <style>
            .button {
            background-color: hsl(14, 94%, 82%); /* Blue */
            font-size: 20px;
            padding-block: 5px;
            border-radius: 10px;
        }

        .img {
          display:block;
          width: 30%;
        }

        </style>        
    </head>
    <body>
        <img src="https://i.ibb.co/KrrWctB/livebryte.png"  alt="livebryte" style="height:100px;"> 

        <h1>New Dose</h1>

        <div>

            <img src="https://i.ibb.co/64d8hqG/compnumbers.png" class="img" alt="compnumbers" border="0">  

                <br><br><form action="/settings/dosechart/editdose/get">
                <p>3 slots for doses available</p>
                <label for=slot>Slot:</label>
                <select id="slot" name="slot">
                    <option value=1>1</option>
                    <option value=2>2</option>
                    <option value=3>3</option>
                </select> 

                <h3>Compartment 1</h3>
                <label for="time1">Time:</label>
                <input type="time" id="time1" name="time1">
                <br><br>

                <label for="dose2">Dose (amount of pills):</label>
                <select id="dose2" name="dose2">
                    <option value=1>1</option>
                    <option value=2>2</option>
                    <option value=3>3</option>
                    <option value=4>4</option>
                </select> 

                <h3>Compartment 2</h3>
                <label for="time2">Time:</label>
                <input type="time" id="time2" name="time2">
                <br><br>

                <label for="dose2">Dose (amount of pills):</label>
                <select id="dose2" name="dose2">
                    <option value=1>1</option>
                    <option value=2>2</option>
                    <option value=3>3</option>
                    <option value=4>4</option>
                </select> 

                <h3>Compartment 3</h3>
                <label for="time3">Time:</label>
                <input type="time" id="time3" name="time3">
                <br><br>

                <label for="dose3">Dose (amount of pills):</label>
                <select id="dose3" name="dose3">
                    <option value=1>1</option>
                    <option value=2>2</option>
                    <option value=3>3</option>
                    <option value=4>4</option>
                </select> 

                <br><br><input type="submit" value="Submit" class="button">
            </form>
        </div>

        <br><br><div>
            <a href="/settings/dosechart">Back to Dose Chart</a><br>
            <a href="/settings">Return to Settings</a><br>
            <a href="/">Return to Homepage</a>
        </div>
    </body>

    <footer>
    <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
    </footer>
</html>
)rawliteral";

return page;
}

String wifi() PROGMEM{
    String wifi=R"rawliteral(
        <!DOCTYPE html>
        <html>
            <head>
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <meta charset="utf-8">
                <title>LIVEBRYTE WIFI</title>
            </head>
            <body>
                <h1>WIFI</h1>
                <div>
                    <H2>Soft AP</H2>
                    SSID : LiveBryte<br>
                    Password : 12345678<br>
                    Gateway : 192.168.4.1
                </div>
                <div>
                    <h2>Local AP</h2>
                    Current local wifi ssid: 
            )rawliteral";

    Preferences pref;
    pref.begin("wifi", true);

    wifi+=pref.getString("ssid");
    pref.end();

    wifi+= R"rawliteral(
        <br>Current local wifi gateway:
    )rawliteral";

    wifi+=returnLocalIP();

    wifi+= R"rawliteral(
            <br>br><div>
                <form action="/get">
                    <label for="ssid">SSID:</label>
                    <input type="text" name="ssid" id="ssid" value="">
                    <br><br>
                    <label for="password">Password:</label>
                    <input type="text" name="password" id="password" value="">
                    <br><br>
                    <input type="submit" value="Submit">
                </form>
            </div>
            
            <div>
                <br><br>
                <a href="/settings">Back to Settings</a><br>
                <a href="/">Back to Home</a>
            </div>
        </body>
        <footer>
            <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
        </footer>
    </html>
    )rawliteral";

    return wifi;
}

String timesetting() PROGMEM{
String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Time</title>
    </head>
    <body>
        <h1>TIME</h1>
        <div>
            <form action="/get">
                <label for="date">Date:</label>
                <input type="date" name="date" id="date" value="">
                <br><br>
                <label for="time">Time:</label>
                <input type="time" name="time" id="time" value="">
                <br><br>
                <input type="submit" value="Submit">
            </form>
        </div>
        <div><br>
            <a href="/settings">Back to Settings</a>
            <br>
            <a href="/">Back to Home</a>
        </div>
    </body>
</html>
)rawliteral";

return page;
}

String phone() PROGMEM{
    String phone = R"rawliteral(
        <!DOCTYPE html>
        <html>
            <head>
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <meta charset="utf-8">
                <title>LIVEBRYTE WIFI</title>
            </head>
            <body>
                <h1>PHONE NUMBER</h1>
                <div>
                    <p>Current Phone Number: )rawliteral";
    
    Preferences pref;
    pref.begin("phone", true);
    phone += pref.getString("phonenumber", "No Phone Number");

    pref.end();

    phone += R"rawliteral(
            </p>
            </div>
            <div>
                <a href="/settings/phone/testcall"><button>Test Call</button></a><br><br>
                <a href="/settings/phone/testmsg"><button>Test SMS</button></a>
            </div>
            <div>
                <p>Enter phone number in +94123456789 format<br>
                    Number should be of Sri Lankan Carriers.</p>

                <form action="/get">
                    <label for="phonenumber">New Phone:</label>
                    <input type="tel" name="phonenumber" id="phonenumber" value="">
                    <br><br>
                    <input type="submit" value="Submit">
                </form>
            </div>
            <div>
                <br><br>
                <a href="/settings">Back to Settings</a><br>
                <a href="/">Back to Home</a>
            </div>
        </body>
        <footer>
            <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
        </footer>
    </html>
    )rawliteral";

    return phone;
}

String chooseCompartment() PROGMEM{
String page = R"rawliteral(
    <!DOCTYPE html>
    <html>
        <head>
        <style>
            .center {
            margin: auto;
            text-align: center;
            }

            .img {
            display:block;
            margin-left: auto;
            margin-right: auto;
            width: 40%;
            }

            .button {
            background-color: #91d6ec; /* Blue */
            padding: auto;
            font-size: large;
            
            } 

            </style>

            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <meta charset="utf-8">
            <title>LIVEBRYTE Compartments</title>
        </head>
        <body>
            <h1>Choose Compartment</h1>
            <div>
                <a href="/cs1"><button class="button">Compartment 1</button></a><br><br>
                <a href="/cs2"><button class="button">Compartment 2</button></a><br><br>
                <a href="/cs3"><button class="button">Compartment 3</button></a><br><br>
                <img src="https://i.ibb.co/64d8hqG/compnumbers.png" class="img" alt="compnumbers" border="0">        
            </div>
            <div>
            <br><br>
            <a href="/settings">Back to Settings</a><br>
            <a href="/">Back to Home</a>
            </div>   
        </body>
        <footer>
            <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
        </footer>
    </html>
)rawliteral";

return page;
}

String compartmentsettings(int compID) PROGMEM{

String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>LIVEBRYTE Compartment Settings</title>

        <style>
            .button {
            background-color: hsl(14, 94%, 82%); /* Blue */
            font-size: 30px;
            padding-block: 5px;
            border-radius: 10px;
        }

        </style>        
    </head>
    <body>
        <h1>Compartment )rawliteral";

page += compID;

page += String(R"rawliteral(
        </h1>

           <a href="cs)rawliteral") + compID + R"rawliteral(/dispense"><button class="button">DISPENSE</button></a><br><br>

        <div>
)rawliteral";

String anchor1 = String(R"rawliteral(            <a href="cs)rawliteral") + compID + R"rawliteral(/calibrate"><button>Calibrate</button></a><br><br>)rawliteral" + "\n";
String anchor2 = String(R"rawliteral(            <a href="cs)rawliteral") + compID + R"rawliteral(/name"><button>Name</button></a><br><br>)rawliteral" + "\n";
String anchor3 = String(R"rawliteral(            <a href="cs)rawliteral") + compID + R"rawliteral(/dose"><button>Dose</button></a><br><br>)rawliteral" + "\n";

page += anchor1;
page += anchor2;
page += anchor3;

page += R"rawliteral( 
        </div>
        <div>
            <br><br>
            <a href="/settings/choosecompartment">Back to Choosing Compartments</a><br>
            <a href="/settings">Back to Settings</a><br>
            <a href="/">Back to Home</a>
        </div>
    </body>
    <footer>
        <p>Individual Design Project<br>B. M. C. D. Bandara<br>D/ENG/20/0067/ET</p>
    </footer>
</html>
)rawliteral";

return page;
}

//...........................................................................................................

String processing(int delay) PROGMEM{
String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <meta http-equiv="refresh" content=")rawliteral";

page += delay;

page+= R"rawliteral(">
        <title>Processing</title>
    </head>
    <body>
        <h1>Processing... </h1>
        <div>
        </div>
    </body>
</html>
)rawliteral";

return page;
}

String processed() PROGMEM{
String page = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="utf-8">
        <title>Processed</title>
    </head>
    <body>
        <h1>Processed 👍 </h1>
        <div>
            <h2><a href="/settings">Back to Settings</a></h2>
        </div>
    </body>
</html>
)rawliteral";

return page;
}