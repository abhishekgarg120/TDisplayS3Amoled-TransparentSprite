#define LILYGO_TDISPLAY_AMOLED_SERIES

#include "LilyGo_AMOLED.h"
#include <TFT_eSPI.h>
#include "FullMoon.h"
#include "Spider.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);
TFT_eSprite moonSprite = TFT_eSprite(&tft);
TFT_eSprite spiderSprite = TFT_eSprite(&tft);

LilyGo_Class amoled;

// WIDTH=536, HEIGHT=240
#define WIDTH amoled.height()
#define HEIGHT amoled.width()


int x = 0;
int y = 56;

void setup() {
  amoled.begin();

  sprite.createSprite(WIDTH, HEIGHT);  
  sprite.setSwapBytes(true);
  
  moonSprite.createSprite(128, 128);
  spiderSprite.createSprite(128, 128);  

  draw();  
}

void draw(){
  sprite.fillSprite(TFT_BLACK);

  
  moonSprite.pushImage(0, 0, 128, 128, FullMoon);
  moonSprite.pushToSprite(&sprite, 20, 20, TFT_WHITE);

  spiderSprite.pushImage(0, 0, 128, 128, Spider);
  spiderSprite.pushToSprite(&sprite, x, y, TFT_WHITE);

  amoled.pushColors(0, 0, WIDTH, HEIGHT, (uint16_t*)sprite.getPointer());
}

void loop() {
  x++;
  if (x > WIDTH){
    x=-128;
  }
  draw();
}
