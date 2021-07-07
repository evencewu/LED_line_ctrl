#ifndef CALLBACK
#define CALLBACK

void mode1_callback(const String & state){
    mode = 1;
}

void mode2_callback(const String & state){
    mode = 2;
}

void ws2812_callback(uint8_t r_value, uint8_t g_value, uint8_t b_value, uint8_t none)
{
    r_value_want = r_value;
    g_value_want = g_value;
    b_value_want = b_value;
}

void Open_callback(const String & state)
{
  bright_value_want = 255;
}

void lt_callback(int bright_value){
  bright_value_want = 256 - bright_value;
}

void Speed_callback(int Speed_value){
  speed_value_want = Speed_value;
}
#endif
