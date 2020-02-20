# Smart Door Lock by Carson Harvey
This project turns any deadbolt door lock into an electronic IOT lock with a NodeMCU ESP8266 and a servo. The lock is connected to the internet through Blynk and can be controlled through a phone app, NFC tag in combination with IOS shortcuts / Android Tasker, and a physical button.  

**Items needed:**
  - NodeMCU ESP8266 (http://bit.ly/AmazonNodeMCU)
  - TowerPro MG995R High Torque Servo (http://bit.ly/adafuitservo)
  - Push Button (http://bit.ly/AmazonPushButtons)
  - Jumper Wires (http://bit.ly/AmazonJumperWires)
  - NFC Tags (http://bit.ly/AmazonNFCTags)
  - Access to a 3D Printer to make the enclosure
  - 2 MicroUSB cables
  - Soldering iron and solder
  - Wire cutter
  - Wire stripper
  
  **Blynk Setup:**
   1. Download the blynk app on your mobile device.
   2. Create a new project and name it whatver you would like. Choose ESP8266 as the device and WiFi for the connection type. 
   3. Once you make the project you should receive an Auth Token in your email. You will need this later when setting up the ESP8266.
   4. Click anywhere in the project area and add a button. Name it whatever you'd like. Set the output to be V0 with 0 and 1 being the          options. Change the mode to switch, and label the on and off to be whatever you'd like.
   5. Select the project area again and add the notification widget. 
   6. If you have multiple people that you would like to grant access to the lock you can go into the project settings and generate a            link to share with others. 
    
   **ESP8266 Setup:**
   1. Plug it into your computer with a micro usb cable. Make sure that the cable is not just power only! 
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
   
   **3D Printed Enclosure:**
   
   You can download the STL files in the repository. If you don't personally have a 3D printer, most public libraries and universities      have one. Additionally, you can use a service like ShapeWays to have the parts printed and mailed to you. Feel free to design and        print your own enclosure, or make it out of wood or something.
   
   **Connecting everything together:**
   
   ![Circuit Diagram](https://i.ibb.co/XSDXpX3/circuit.png)
   
   1. Start by modifying one of the USB cables to supply power to the servo. Cut MicroUSB connector off of the end of the cable. Strip         back the sheathing on the positive (usually red) wire and the negative (usually black) wire. The other wires are not necessary for       powering the servo and can be cut away or folded back. Take three of the male to female jumper wires and cut the female ends off         of them. Strip back some of the sheathing and solder one jumper wire to the positive USB wire and the other two jumper wires to         the negative USB wire. Use electrical tape or heatshrink to strengthen and protect the solder joints. What you should be left with       is a male USB plug on one end and three male jumper wires on the other end (one connected to positive, two connected to ground). 
   2. Connect the positive USB jumper wire to the positve wire and one of the negative USB jumper wires to the negative wire on the           servo. Connect the other negative jumper wire to a GND pin on the ESP8266. 
   3. Take another male to female jumper wire and connect the male end to the signal (usually yellow) wire on the servo. Connect the           female end to pin D4 (GPIO 2) on the ESP8266.
   4. Take two male to female jumper wires and cut the male ends off. Strip back some of the sheathing and solder one wire to the             positive terminal on the button and the other jumper wire to the negative terminal on the button. 
   5. Connect one of the jumper wires that is connected to the button to a GND pin on the ESP8266 and the other jumper wire to the TX         (GPIO 0) pin.
   6. Once everything is connected, power the ESP8266 with a MicroUSB cable and plug the servo power USB cable in as well. 
   7. At this point, everything should be working. Test it out by pushing the physical button or the button in the Blynk app. 
   8. If all is working as it should, attach everything to the 3D printed housing and stick it on the door. I used velcro command strips       to make the entire thing easily removable. 
   
   **Setting up the NFC tags:**

   I have an iPhone so these steps will be specific to the Shortcuts app, but it should be very similar on the Android Tasker app. 
   
   1. Download the Shortcuts app if you haven't already and open it.
   2. Go to the Automation tab and click the blue + in the upper right. 
   3. Select Personal Automation.
   4. Scroll down and select the NFC option.
   5. Click the scan button and tap your phone on one of the NFC stickers. The NFC reader on the iPhone 11 is in the upper middle             section on the back of the phone.
   6. Once you have the NFC tag scanned, set the action to Get Contents of URL.
   7. The URL will be the IP address of Blynk's server in combination with your Blynk Auth Token. To find the Blynk IP address, open a         command or terminal window and ping Blynk-Cloud.com. At the time of writing it is 45.55.96.146. This is how the URL should look:
      **http://45.55.96.146/*YOURAUTHTOKEN*/update/V0?value=0**
      This shortcut will unlock the door whenever your phone scans the NFC tag. Repeat the above steps to make a shortcut that locks the       door, but change the *value=0* at the end of the URL to *value=1*. Once you have the shortcuts made, you can click on them and           toggle the Ask Before Running setting to off so that the door will unlock/lock as long as your screen is awake. I have also foound       that shortcuts do not run while on a FaceTime call. 
      
      
      
      
      Thats it! Enjoy the convenience of your new smart lock. If you have any questions I will try to answer them as best as I can. 
  
    
    
  
  
