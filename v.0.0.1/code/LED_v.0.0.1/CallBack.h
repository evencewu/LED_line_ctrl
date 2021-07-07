#ifndef CALLBACK
#define CALLBACK

void mode1_callback(const String & state){
    mode = 1;
}

void mode2_callback(const String & state){
    mode = 2;
}

void ws2812_callback(uint8_t r_value, uint8_t g_value, uint8_t b_value, uint8_t bright_value)
{
    r_value_want = r_value;
    g_value_want = g_value;
    b_value_want = b_value;
    bright_value_want = bright_value;
}
#endif
