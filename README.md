# SmartDoorLock
This project turns any deadbolt door lock into an electronic IOT lock by using an NodeMCU ESP8266 and a servo. The lock is connected to the internet through Blynk and can be controlled through a phone app, NFC tag in combination with IOS shortcuts/ Android Tasker, and a physical button.  

**Items needed:**
  - NodeMCU ESP8266 (http://bit.ly/AmazonNodeMCU)
  - TowerPro MG995R High Torque Servo (http://bit.ly/adafuitservo)
  - Push Button (http://bit.ly/AmazonPushButtons)
  - Jumper Wires (http://bit.ly/AmazonJumperWires)
  - NFC Tags (http://bit.ly/AmazonNFCTags)
  - Access to a 3D Printer to make the enclosure
  
  **Blynk Setup:**
   *1. Download the blynk app on your mobile device.
    2. Create a new project and name it whatver you would like. Choose ESP8266 as the device and WiFi for the connection type. 
    3. Once you make the prject you should receive an Auth Token in your email. You will need this later when setting up the ESP8266.
    4. Click anywhere in the project area and add a button. Name it whatever you'd like. Set the output to be V0 with 0 and 1 being the          options. Change the mode to switch, and label the on and off to be whatever you'd like.
    5. Select the project area again and add the notification widget. 
    6. If you have multiple people that you would like to grant access to the lock you can go into the project settings and generate a            link to share with others. 
    
   **ESP8266 Setup:**
   *1. Plug it into your computer with a microusb cable. Make sure that the cable is not just power only! 
    2. Download Arduino IDE here: https://www.arduino.cc/en/main/software
    3. Make sure that you have installed the proper drivers for the ESP8266 as well. Those can be found here:                                  https://github.com/nodemcu/nodemcu-devkit/tree/master/Drivers
    4. In the Arduino IDE go to File -> Preferences and make sure that this URL is in the Additional Boards Manager URLs section:              http://arduino.esp8266.com/stable/package_esp8266com_index.json
    5. Under the Tools tab, go to manage libraries and search for and install Blynk, and also make sure that the Servo library is              updated and installed as well.
    6. Under the Tools tab, select Board -> Boards Manager and then search for ESP8266. Install the latest version. 
    7. Back under the Tools tab select Board and then choose the NodeMCU 1.0 (ESP-12 Module) from the list. 
    8. Still under the Tools tab change CPU frequency to 80 Mhz, the upload speed to 921600, and the flash size to 4MB (FS:3MB...)
    9. Copy and paste the code from SmartLock.ino in this repository, or download and open the file in the Arduino IDE. 
    10. Enter in your Blynk Auth Token and WiFi details in their respective fields.
    11. You may need to adjust the lockedState and unlockedState variables depending on your lock. 
    12. Once you are ready to upload the code go to the Sketch tab and click the upload button. 
    
    
  
  
