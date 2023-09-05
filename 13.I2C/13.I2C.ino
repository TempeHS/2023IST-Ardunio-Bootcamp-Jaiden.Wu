/*
  Author: Jaiden Wu
  Learning Intention: The students will learn to use the I2C communication protocol to send and receive data with 2IC sensors and actuators
    1. I understand that I2C is a communication protocol
    2. I understand that each I2C needs it's own I2C Channel
    3. I understand that communicating to I2C modules is similar to the serial monitor
    4. I undersatdn I need to include the `wire-h` library
    5. I understand that I need to look at the documentation and example code for each I2C module
    6. I can sucessfully send data to the I2C OLED display
    7. I can successfully receive data from either Temperature & Humidity Sensor, Air pressure Sensor or Acceleration Sensor in the sensor kit.

  Student Notes:
    
  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/communication/wire/


  Schematic:

*/

//The Wire-h library is built into Ardunio IDE there is no need to side load it like the Ultrasonic Sensor library

//Includes for IC2 comm
#include <Arduino.h>
#include <Wire.h>

//Include for OLED Display
#include <U8g2lib.h>

//Include for Air Pressure Sensor
#include "Seeed_BMP280.h"

//Strings to hold lines in OLED Display 
String MyMessage = "1st Line of OLED";
String MyMessage2 = "2nd Line of OLED";

//Configure for OLED display copied from library
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C

//Setup pressure sensor object
BMP280 bmp280;

void setup(void) {
//begin comms with OLED
u8g2.begin();

Serial.begin(9600);
Serial.println(Serial Monitor is Configured)
Serial.println ("---------------------------")

//begin comms with pressure sensor 
if(!bmp280.init()){          // init = intialised,  != false // so if bmp280 is not intialised, it will return the message 
  Serial.println("Device Error!!");
  }
}

void loop() {

  //read pressure sensor
  float myPressure = bmp280.getPressure();
  float myTemp = bmp280.getTempearture();
  float my Altitude = bmp280.calcAltitude(myPressure);

//message for OLED
MyMessage = "Howdy!!";
MyMessage2 = "The temperature is currently:" + String(myTemp) + "c";       //converted float to string to show on OLED

//print to OLED
printToOLED (MyMessage, myMessage2);
}