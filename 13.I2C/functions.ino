
// Function to update OLED Display
void printToOLED (float theTemp, float thePressure) {
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.setCursor(0,10);                 // set cursor for 1st line
  u8g2.print("Hello Jaiden!");          // write something to the internal memory
  u8g2.setCursor(0,20);                 // set cursor for 2nd line
  u8g2.print("The temperature is");          // write something to the internal memory
  u8g2.print("theTemp");                     // write temperature here
  u8g2.print("c"); 

  u8g2.sendBuffer();                    // transfer internal memory to the display
}

float myTemp(){
  return bmp280.getTempeature();        // receives tempeature 
}

float myPressure(){
  return bmp280.getPressure();          // receives pressure 
}