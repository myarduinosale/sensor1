#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

void setup() {
display.begin(SH1106_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0, 5);

display.println("WELCOME to Myarduino");
display.println();
display.setTextSize(2);
display.println("Myarduino");
display.setTextSize(1);
display.println("...OLED 1.3 TESTER...");
display.display();
delay(5000);
}
void loop() {
}
