#ifndef MODE_H
#define MODE_H

void Mode_1()
{
  for(int n = 0 ; n < 120 ; n++)
  {
    if(n < 60)
    {
      strip2.setPixelColor(60 - n, r_value_want/bright_value_want,  g_value_want/bright_value_want, b_value_want/bright_value_want);  
    }
    else if(n >= 60 && n < 120)
    {
      strip1.setPixelColor(n - 60, r_value_want/bright_value_want,  g_value_want/bright_value_want, b_value_want/bright_value_want);
    }  
    else 
    {
      break;
    }
  }
}

void Mode_2()
{
    for(int n = 320 ; n > 0 ; n--)
    {
      base_r[n] = base_r[n-1];
      base_g[n] = base_g[n-1];
      base_b[n] = base_b[n-1];
    }
    
    while(base_r[0] == 255 && base_g[0] < 255 && base_b[0] == 0)
    {
       base_g[0] = base_g[0] + 5*speed_value_want;
       break;
    }
    
    while(base_r[0] > 0 && base_g[0]  == 255 && base_b[0]  == 0)
    {
       base_r[0] = base_r[0] - 5*speed_value_want;
       break;
    }

    while(base_r[0]  == 0 && base_g[0]  == 255 && base_b[0] < 255)
    {
       base_b[0] = base_b[0] + 5*speed_value_want;
       break;
    }

    while(base_r[0]  == 0 && base_g[0] > 0 && base_b[0]  == 255)
    {
       base_g[0] = base_g[0] - 5*speed_value_want;
       break;
    }

    while(base_r[0] < 255 && base_g[0]  == 0 && base_b[0]  == 255)
    {
       base_r[0] = base_r[0] + 5*speed_value_want;
       break;
    }

    while(base_r[0]  == 255 && base_g[0]  == 0 && base_b[0] > 0)
    {
       base_b[0] = base_b[0] - 5*speed_value_want;
       break;
    }

    while(base_r[0] > 256)
    {
      base_r[0] = 255;
      break;
    }
    while(base_r[0] < 0)
    {
      base_r[0] = 0;
      break;
    }
    
    while(base_g[0] > 256)
    {
      base_g[0] = 255;
      break;
    }
    while(base_g[0] < 0)
    {
      base_g[0] = 0;
      break;
    }
    
    while(base_b[0] > 256)
    {
      base_b[0] = 255;
      break;
    }
    while(base_b[0] < 0)
    {
      base_b[0] = 0;
      break;
    }

    
    for(int n = 0 ; n < 120 ; n++)
    {
      if(n < 60)
      {
        strip2.setPixelColor(60 - n, base_r[n]/bright_value_want,  base_g[n]/bright_value_want, base_b[n]/bright_value_want);  
      }
      else if(n >= 60 && n < 120)
      {
        strip1.setPixelColor(n - 60, base_r[n]/bright_value_want,  base_g[n]/bright_value_want, base_b[n]/bright_value_want);
      }  
      else 
      {
        break;
      }
    }
}

void Mode_change(int mode){
  if(mode == 1){
    Mode_1();
  }else if(mode == 2){
    Mode_2();
  }
  
}

#endif
