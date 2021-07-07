#define BLINKER_WIFI
#include <Blinker.h>
#include <Adafruit_NeoPixel.h>
//#include <iostream>

#define PIXELPIN 1

#define NUM_LEDS 60             // LED灯珠数量

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, D8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, D7, NEO_GRB + NEO_KHZ800);

//设置wifi
char auth[] = "0901d074790a";
char ssid[] = "evence";
char pswd[] = "20040220";

//设置按钮
BlinkerButton Open("open");
BlinkerButton mode1("mode1");
BlinkerButton mode2("mode2");
BlinkerRGB WS2812_("RGBKey");
BlinkerSlider lt("lt");
BlinkerSlider Speed("speed");

//初始化灯光
uint8_t r_value_want = 0;
uint8_t g_value_want = 255;
uint8_t b_value_want = 255;
uint8_t bright_value_want = 1;
uint8_t speed_value_want = 0;

//初始化模式
int mode = 2;

#include "CallBack.h"
int base_r[500] = {255};


int base_g[500] = {0};


int base_b[500] = {0};


int base_light;

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    Blinker.begin(auth, ssid, pswd);

    mode1.attach(mode1_callback);
    mode2.attach(mode2_callback);
    WS2812_.attach(ws2812_callback);
    Open.attach(Open_callback);
    lt.attach(lt_callback);
    Speed.attach(Speed_callback);
    strip1.begin();
    strip2.begin();
}

#include "Mode.h"
void loop()
{
    Blinker.run();
    Mode_change(mode);
    strip1.show();
    strip2.show();
    
   
}
