#include "LM4F120H5QR.h"

void LED_init();
void SW_init();

int main()
{
  SYSCTL->RCGCGPIO |= 1<<5;    //GPIO Port F RMCGC
  SYSCTL->GPIOHBCTL |= 1<<5;   //AHB enable
  LED_init();
  SW_init();
  //GPIOF_AHB->DATA &= ~(1<<2);
  //GPIOF_AHB->DATA |= 1<<2;
  while(1)
  {
    GPIOF_AHB->DATA |= 1<<1;
    GPIOF_AHB->DATA &= ~(1<<1);     //red
    GPIOF_AHB->DATA |= 1<<2;
    GPIOF_AHB->DATA &= ~(1<<2);     //blue
    GPIOF_AHB->DATA |= 1<<3;
    GPIOF_AHB->DATA &= ~(1<<3);     //green
  }
}

void LED_init()
{
    GPIOF_AHB->DIR |= 0xE;       //Set pin as output    
    //GPIOF->AFSEL = 0x0;     //AF select 0
    GPIOF_AHB->DEN |= 0xE;
}

void SW_init()
{
    GPIOF_AHB->DIR &= ~(0x11);       //Set pin as output
    //GPIOF_AHB->AFSEL = 0x0;     //AF select 0
    GPIOF_AHB->DEN |= 0x11;       //Set pin as digital
}
