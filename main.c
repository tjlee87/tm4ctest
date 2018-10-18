#include "LM4F120H5QR.h"

int main()
{
  while(1)
  {
    SYSCTL->RCGCGPIO = 1<<5;    //GPIO Port F RMCGC
    SYSCTL->GPIOHBCTL = 1<<5;   //AHB enable
    GPIOF_AHB->DIR = 0xE;       //Set pin as output
    GPIOF_AHB->AFSEL = 0x0;     //AF select 0
    GPIOF_AHB->DEN = 0xE;       //Set pin as digital
    GPIOF_AHB->DATA = 0<<1;     //red
    GPIOF_AHB->DATA = 1<<1;
    GPIOF_AHB->DATA = 0<<2;     //blue
    GPIOF_AHB->DATA = 1<<2;
    GPIOF_AHB->DATA = 0<<3;     //green
    GPIOF_AHB->DATA = 1<<3;
  }
}
