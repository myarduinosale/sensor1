#include <TridentTD_7Segs74HC595.h>
#define SCLK        4
#define RCLK        5
#define DIO         6

TridentTD_7Segs74HC595  my7SEGMENT( SCLK, RCLK, DIO);


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(my7SEGMENT.getVersion());

  my7SEGMENT.init();
  my7SEGMENT.setText("1234");
}

void loop() {
}
