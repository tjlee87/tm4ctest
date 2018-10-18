#include "LM4F120H5QR.h"

int main()
{
  while(1)
  {
    SYSCTL->RCGCGPIO = 1<<5;    //GPIO Port F RMCGC
    SYSCTL->GPIOHBCTL = 1<<5;   //AHB enable
    GPIOF_AHB->DIR = 0xE;
    GPIOF_AHB->AFSEL = 0x0;
    GPIOF_AHB->DEN = 0xE;
    GPIOF_AHB->DATA = 0<<1;
    GPIOF_AHB->DATA = 1<<1;
    GPIOF_AHB->DATA = 0<<2;
    GPIOF_AHB->DATA = 1<<2;
    GPIOF_AHB->DATA = 0<<3;
    GPIOF_AHB->DATA = 1<<3;
  }
  //return 0;
}
