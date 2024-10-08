/*
Ellie Sundheim, esundheim@hmc.edu
9-24-24
This file contains the source code for setting up timers 15 or 16 on the STM32L432KC
*/

#include "STM32L432KC_TIM1516.h"


void initTIM1516(TIM_TypeDef * TIMx){
  // input the system clock to prescaler by setting SMS[3:0] to 0000
  TIMx->SMCR &= ~(1<<16);
  TIMx->SMCR &= ~(0b111 << 0);

  // set prescale to 9,999 since divide by psc + 1 and want to prescale duration by 10,000 to get CK_CNT at 8 kHz
  TIMx->PSC &= 0;
  TIMx->PSC = 799;

  // set auto reset register to reset value
  TIMx->ARR = 0xFFFF;
  
  // enable counter by setting CEN bit in CR1
  TIMx->CR1 |= 1 << 0;

  //initialize all registers by setting UG bit (0)in EGR register
  TIMx->EGR |= (1 << 0);


}


void delay_millis1516(TIM_TypeDef *TIMx, uint32_t ms){
  // this function 1) resets the counter then 2) waits until we hit the counter value calculated using the duration and the known freq of timer 3
  TIMx->EGR |= (1 << 0);
  volatile uint32_t duration = 100*ms; // 8 kHz* x ms = 8x clock cycles
  TIMx->ARR = duration;
  // reset UIF flag (bit 0)
  TIMx->SR &= ~(1 << 0); 
  // when the timer hits ARR value, it will raise the flag in SR, bit 0 (UIF) and then we exit
  //while( (TIMx->SR &= 0b1) == 0){}; this way works but is annoying to mask bits that are somewhere in the middle
  while ( ((TIMx->SR >> 0) & 1) == 0 ){};

}

