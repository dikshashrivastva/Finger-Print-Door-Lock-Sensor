
/*
  Project: Fingerprint Door Lock Sensor
  Description: Arduino-based fingerprint authentication system to control a solenoid lock using a fingerprint sensor.
  Components:
    - Arduino Uno
    - R305 fingerprint sensor module
    - Solenoid lock
    - Relay module
    - 12V power supply
    - Jumper wires

  Author: Devansh Verma
  
*/

#include <Adafruit_Fingerprint.h>
#include "Servo.h"

SoftwareSerial mySerial(2, 3);
Servo myservo;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);




#define ACCESS_DELAY    5000 


void setup()

{
  myservo.attach(4);
  myservo.write(90);
  

  finger.begin(57600);

  delay(5);

  if (finger.verifyPassword()) 

  {

  } 

  else 

  {

    while (1) { delay(1); }

  }

  



   

}



void loop()

{

  if ( getFingerPrint() != -1)

  {

  myservo.write(45); 
  delay(5000); 

    myservo.write(90); 
  delay(5000); 

    delay(ACCESS_DELAY);

myservo.write(135); 
  delay(5000); 
  
myservo.write(90); 
  delay(5000); 

      

  }  

  delay(10);            

}





int getFingerPrint() 

{

  int p = finger.getImage();

  if (p != FINGERPRINT_OK)  return -1;



  p = finger.image2Tz();

  if (p != FINGERPRINT_OK)  return -1;



  p = finger.fingerFastSearch();

  if (p != FINGERPRINT_OK)  return -1;



  

  return finger.fingerID;

}