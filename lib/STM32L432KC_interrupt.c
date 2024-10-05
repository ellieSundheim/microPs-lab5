// STM32L432KC_interrupt.c
// Source code for interrupt functions

#include "STM32L432KC_interrupt.h"


void initInterrupt(int pin_num){
  //map GPIO to an exti line
  SYSCFG->EXTICR[pin_num / 4] &= 0b000 << ((pin_num % 4) *4); //exticr is a list, there are 4 registers per list and their bits are 2:0, 6:4, 10:8, 14:12

  // config exti input mask register
  EXTI->IMR1 |= 1 << pin_num;

  //config rising and falling triggers to generate interrupts
  EXTI->RTSR1 |= 1 << pin_num;
  EXTI->FTSR1 |= 1 << pin_num;

  //config NVIC to accept GPIO
  // this info comes from the ARM Reference Manual, not the STM32L432 rm
  if ((pin_num >= 10) & (pin_num <= 15)){
    NVIC->ISER[0] |= 1 << 40 ;  //set the 40th bit in the first register of the list of register values to 1 in order to enable exti 15-10???????
  } 
  else if ((pin_num >= 5) & (pin_num <= 9)){
    NVIC->ISER[0] |= 1 << 23; //set the 23rd bit in the first register of the list of register to 1 in order to enable exti 9-5
  }


}

