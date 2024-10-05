/*
Ellie Sundheim, esundheim@hmc.edu
9-24-24
This file contains the source code for setting up timers 2 or 3 on the STM32L432KC
*/

#include "STM32L432KC_TIM23.h"

void initTIM(TIM23_TypeDef * TIMx){
  // input the system clock to prescaler by setting SMS[3:0] to 0000
  TIMx->SMCR &= ~(1<<16);
  TIMx->SMCR &= ~(0b111 << 0);

  // set prescale to 19,999 since divide by psc + 1 and want to prescale duration by 20,000 to get CK_CNT at 4 kHz
  TIMx->PSC &= 0;
  TIMx->PSC |= 0b100111000011111;

  // set auto reset register to reset value
  TIMx->ARR = 0xFFFFFFFF;
  
  // enable counter by setting CEN bit in CR1
  TIMx->CR1 |= 1 << 0;

}

void initTIM_PWM(TIM23_TypeDef * TIMx){
  // input the system clock to prescaler by setting SMS[3:0] to 0000
  TIMx->SMCR &= ~(1<<16);
  TIMx->SMCR &= ~(0b111 << 0);

  // set prescale to 199 since divide by psc + 1 to get CK_CNT at 400 kHz (799 and 100 khz)
  //TIMx->PSC &= 0;
  TIMx->PSC |= 199;
  //TIMx->PSC |= 0x31F; 
  //TIMx->PSC |= 0b100111000011111; // set CK_CNT at 4kHz for testing with LED 

  // set auto reset register to reset value
  TIMx->ARR = 0xFFFFFFFF;
  // set ccr2 arbitrarily (we compare counter to this num, gives us duty cycle) (use equals because we don't want to preserve other bits)
  TIMx->CCR2 = 0x0000FFFF;

  // select PWM mode 1 (110) by setting OC2M bits (14:12) in TIM2_CCMRx register - do this in CCMR2 so that we can output
  TIMx->CCMR1 |= (0b110 << 12);
  // enable preload register by setting OC2PE bit (11) in CCMRx register
  TIMx->CCMR1 |= (1 << 11);
  // set auto reload preload register ARPE bit (7) in CR1 register
  TIMx->CR1 |= (1 << 7);
  //initialize all registers by setting UG bit (0)in EGR register
  TIMx->EGR |= (1 << 0);

  // enable counter by setting CEN bit (0) in CR1
  TIMx->CR1 |= (1 << 0);
  // enable channel 2 output CC2E bit 4 in CCER
  TIMx->CCER |= (1 << 4);

}

void update_freq(TIM23_TypeDef * TIMx, uint32_t newFreq){
  // catch rests before we divide by 0
  if (newFreq == 0){
    TIMx->ARR = 0xFFFFFFFF; //???????????????????????I'm concerned this will still limit the duration of my rests
  }
  else{
  // convert freq to ARR by dividing ck_CNT freq (100kHz) by new freq 
  volatile uint32_t newARR = 400E3 / newFreq;
  TIMx->ARR = newARR;

  //keep duty cycle at 50%
  TIMx->CCR2 = newARR/2;

  //make updates take effect
  TIMx->EGR |= 1 << 0;
  }
}

void delay_millis(TIM23_TypeDef *TIMx, uint32_t ms){
  // this function 1) resets the counter then 2) waits until we hit the counter value calculated using the duration and the known freq of timer 3
  TIMx->EGR |= (1 << 0);
  volatile uint32_t duration = 4*ms; // 4 kHz* x ms = 4x clock cycles
  while(TIMx->CNT - duration > 0){}; 

}

