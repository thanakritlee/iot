#include <Arduino.h>

// Include the SSD1306 display library.
#include "SSD1306.h"

// Initialise the OLED display.
SSD1306 display(0x3c, 5, 4);

void printHelloWorld(void) {
  
  // Initialise the log buffer.
  display.setLogBuffer(5, 30);

  display.clear();
  // Print to the screen.
  display.println("Hello World");
  // Draw to the internal screen buffer.
  display.drawLogBuffer(0, 0);
  // Display on the screen.
  display.display();

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello World");

  display.init();
  printHelloWorld();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}