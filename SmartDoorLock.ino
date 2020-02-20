/* Copyright (c) 2020 Carson Harvey
   This code is licensed under GNU General Public License v3.0 */

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "PASTE HERE"; /* Blynk Auth Token */
char ssid[] = "ENTER HERE"; /* WiFi name */
char pass[] = "ENTER HERE"; /* WiFi Password */
const int lockedState = 115; /* Degree the servo rotates to when locked. You may need to tweak this depending on your door. */
const int unlockedState = 20; /* Degree the servo rotates to when unlocked. You may need to tweak this depending on your door. */
const int buttonPin = 1; /* pin that physical button is conncected to */
int buttonState = 0; 
boolean toggle = true; 

Servo servo; 

BLYNK_WRITE(V0)
  {
  int lockState = param.asInt();
  if (lockState == 1) { /* If the button in blynk app is clicked */
    servo.attach(2); /* Attach servo on GPIO 2 (physical pin D4) */
    servo.write(lockedState); /* lock door */
    Blynk.notify("The door has been locked!");
    delay(750); /* Wait 750 ms */
    servo.detach(); /* Detach the servo to prevent stripping the gears if the door is manually unlocked */
    }
  else {
    servo.attach(2); /* Attach servo on GPIO 2 (physical pin D4) */
    servo.write(unlockedState); /* otherwise if lock state is 0, unlock door */
    Blynk.notify("The door has been unlocked!");
    delay(750); /* Wait 750 ms */
    servo.detach(); /* Detach the servo to prevent stripping the gears if the door is manually unlocked */
    }
  }

void setup()
{
  Blynk.begin(auth, ssid, pass); /* Connects to Blynk */
  pinMode(buttonPin, INPUT); /*Sets the button pin as an input */
  digitalWrite(1, HIGH); /* Sets the button pin to the high (unpressed) state as default */
}

void loop()
{
  buttonState = digitalRead(buttonPin); /* reads the current state of the button */
  if (buttonState == LOW) /* if the button is pressed */
  {
    if(toggle)
    {
      servo.attach(2); /* Attach servo on GPIO 2 (physical pin D4) */
      servo.write(lockedState); /* lock the door */
      toggle = !toggle;
      delay(750); /* Wait 750 ms */
      servo.detach(); /* Detach the servo to prevent stripping the gears if the door is manually unlocked */
    }
    else
    {
      servo.attach(2); /* Attach servo on GPIO 2 (physical pin D4) */
      servo.write(unlockedState);
      toggle = !toggle;
      delay(750); /* Wait 750 ms */
      servo.detach(); /* Detach the servo to prevent stripping the gears if the door is manually unlocked */
    }
    delay(500);
  }
  
  Blynk.run(); /* Communication with Blynk */
 
}
