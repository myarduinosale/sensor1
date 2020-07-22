#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8X8_SSD1327_EA_W128128_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup(void)
{
  u8x8.begin();
}

void pre(void)
{
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.inverse();
  u8x8.print(" My Arduino  ");
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.noInverse();
  u8x8.setCursor(1, 0);
}

void loop(void)
{
  pre();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(2, 2, "Welcome to");
  u8x8.draw2x2String(5, 4, "My");
  u8x8.draw2x2String(0, 7, "Arduino");
  u8x8.drawString(1, 10, "myarduino.net");
}
