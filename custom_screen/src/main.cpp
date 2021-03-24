
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 7, /* dc=*/ 6, /* reset=*/ 8);  
// U8X8_SSD1306_128X64_NONAME_4W_HW_SPI u8x8(/* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

// const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
// int outputValue = 0;        // value output to the PWM (analog out)



// pour les fontes  https://github.com/olikraus/u8g2/wiki/fntlistall
// poue l'écran     https://github.com/olikraus/u8g2/wiki/u8g2setupc




void setup(void) {
  Serial.begin(9600);
  u8g2.begin();
}

void loop(void) {
  
  u8g2.setFont(u8g2_font_6x13O_tf);
  u8g2.firstPage();
  do {
    sensorValue = analogRead(A0);
    u8g2.setCursor(0, 10);
    u8g2.print(F("ACAB:"));
    u8g2.setCursor(0, 25);
    u8g2.print(F("Luminosite:"));
    u8g2.setCursor(70, 25);
    u8g2.print(sensorValue);
    u8g2.setCursor(0, 40);
    u8g2.print(F("Heddyestunecatin:"));
    u8g2.setCursor(0, 55);
    u8g2.print(F("Espece:"));
  
  } while ( u8g2.nextPage() );
  delay(100);
}

