#ifndef MODE_H
#define MODE_H

void Mode_1(){
  FastLED.setBrightness(bright_value_want); 
  
  fill_solid(leds, 60, CRGB(r_value_want, g_value_want, b_value_want));
  fill_solid(leds_2, 60, CRGB(r_value_want, g_value_want, b_value_want));    

}

void Mode_2(){
  FastLED.setBrightness(bright_value_want); 
  
  fill_rainbow(leds, 60, base, 4);
  fill_rainbow(leds_2, 60, base, 4);
  base = base + 2;
}

void Mode_change(int mode){
  if(mode == 1){
    Mode_1();
  }else if(mode == 2){
    Mode_2();
  }
  
}

#endif
