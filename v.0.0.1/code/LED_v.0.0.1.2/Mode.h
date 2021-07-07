#ifndef MODE_H
#define MODE_H

int base_r[500] = {255};

int base_g[500] = {0};


int base_b[500] = {0};


int base_light;

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
    for(int n = 1350 ; n > 0 ; n--)
    {
      base_r[n] = base_r[n-1];
      base_g[n] = base_g[n-1];
      base_b[n] = base_b[n-1];
    }
    
    while(base_r[0] == 255 && base_g[0] < 256 && base_b[0] == 0)
    {
       base_g[0] = base_g[0] + 1;
       break;
    }
    
    while(base_r[0] > 0 && base_g[0]  == 255 && base_b[0]  == 0)
    {
       base_r[0] = base_r[0] - 1;
       break;
    }

    while(base_r[0]  == 0 && base_g[0]  == 255 && base_b[0] < 256)
    {
       base_b[0] = base_b[0] + 1;
       break;
    }

    while(base_r[0]  == 0 && base_g[0] > 0 && base_b[0]  == 255)
    {
       base_g[0] = base_g[0] - 1;
       break;
    }

    while(base_r[0] < 256 && base_g[0]  == 0 && base_b[0]  == 255)
    {
       base_r[0] = base_r[0] + 1;
       break;
    }

    while(base_r[0]  == 255 && base_g[0]  == 0 && base_b[0] > 0)
    {
       base_b[0] = base_b[0] - 1;
       break;
    }

    
    for(int n = 0 ; n < 120 ; n++)
    {
      if(n < 60)
      {
        strip2.setPixelColor(60 - n, base_r[n+3*speed_value_want]/bright_value_want,  base_g[n+3*speed_value_want]/bright_value_want, base_b[n+3*speed_value_want]/bright_value_want);  
      }
      else if(n >= 60 && n < 120)
      {
        strip1.setPixelColor(n - 60, base_r[n+3*speed_value_want]/bright_value_want,  base_g[n+3*speed_value_want]/bright_value_want, base_b[n+3*speed_value_want]/bright_value_want);
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
