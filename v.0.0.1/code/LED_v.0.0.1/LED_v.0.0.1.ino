#define BLINKER_WIFI
#include <Blinker.h>
#include "FastLED.h"

//设置wifi
char auth[] = "0901d074790a";
char ssid[] = "evence";
char pswd[] = "20040220";

#define NUM_LEDS 60             // LED灯珠数量
#define DATA_PIN D8              // Arduino输出控制信号引脚
#define DATA_PIN_2 D7             // Arduino输出控制信号引脚

#define LED_TYPE WS2812         // LED灯带型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序

//设置按钮
#define RGB_1 "RGBKey"
BlinkerButton mode1("mode1");
BlinkerButton mode2("mode2");
BlinkerRGB WS2812_(RGB_1);

//初始化灯光
uint8_t r_value_want = 255;
uint8_t g_value_want = 255;
uint8_t b_value_want = 255;
uint8_t bright_value_want = 255;

//初始化模式
int mode = 1;

#include "CallBack.h"

CRGB leds[NUM_LEDS];            // 建立灯带leds
CRGB leds_2[NUM_LEDS];            // 建立灯带leds
void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    Blinker.begin(auth, ssid, pswd);

    LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化灯带
    LEDS.addLeds<LED_TYPE, DATA_PIN_2, COLOR_ORDER>(leds_2, NUM_LEDS);  // 初始化灯带

    mode1.attach(mode1_callback);
    mode2.attach(mode2_callback);
    WS2812_.attach(ws2812_callback);
}
int base = 0;
#include "Mode.h"
void loop()
{
    Blinker.run();
    Mode_change(mode);
    FastLED.show();
   
}
