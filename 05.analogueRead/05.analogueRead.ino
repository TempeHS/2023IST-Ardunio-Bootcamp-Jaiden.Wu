/*
  Author: 
  Learning Intention: The students will learn how to wire a variable resistor as a pseudo sensor and read analogue data from that PIN.
  Success Criteria:
    1. I can wire a variable resistor in TINKERCAD
    2. I know how to read analogue data from a specific PIN
    3. I know the range of analogue data
    4. I can organise output data so it correctly plots on the serial monitor
    5. I can apply this knowledge to the Light, Sound and Rotary Potentiometer in the sensor kit

  Student Notes: 
Range of analogue data: 0-1023
  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
  Schematic:
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/05.serialRead/Bootcamp-serialRead.png
*/

static unsigned int myVarResistor = A0;
static unsigned int mySound = A2;
static unsigned int myLight = A3;



void setup() {
Serial.begin(9600);
Serial.println("Serial Monitor Configured to 9600");
Serial.println("-----------------");
}

void loop() {
unsigned int val = analogRead(myVarResistor);
Serial.print("PotentiometerValue:");
Serial.print (val);
Serial.print (",");

unsigned int senVal = analogRead(mySound);
Serial.print("mySoundValue:");
Serial.print (senVal);
Serial.print (",");

unsigned int benVal = analogRead(myLight);
Serial.print("myLightValue:");
Serial.print (benVal);
Serial.print (",");

Serial.println (); 



}