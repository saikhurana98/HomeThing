#include <Arduino.h>

#include <SPI.h>
#include <U8g2lib.h>
#include <ESP32Encoder.h>

#include "FastLED.h"
#include "./pins.h"

/* Constructor */
U8G2_ST7567_JLX12864_F_4W_SW_SPI u8g2(U8G2_R2, LCD_SCK, LCD_MOSI, LCD_CS, LCD_RS, LCD_RST);
CRGB leds[NUM_LEDS];
ESP32Encoder encoder;

/* u8g2.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
  u8g2.begin();
  u8g2.setContrast(165);
  FastLED.addLeds<WS2811, RGB>(leds, NUM_LEDS);

  ESP32Encoder::useInternalWeakPullResistors = UP;
  encoder.attachHalfQuad(ENC_A, ENC_B);
  leds[2] = CRGB::DeepPink;
  FastLED.show();
}

void loop(void)
{
}
