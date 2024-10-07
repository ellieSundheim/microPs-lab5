/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include <stm32l432xx.h>
#include "../lib/STM32L432KC_FLASH.h"
#include "../lib/STM32L432KC_GPIO.h"
#include "../lib/STM32L432KC_RCC.h"
#include "../lib/STM32L432KC_TIM1516.h"
#include "../lib/STM32L432KC_interrupt.h"
#include "../lib/print_f.h"

#define A_PIN 8
#define B_PIN 10

int testmain(void) {
  int i;

  for (i = 0; i < 100; i++) {
      // printf function call
    printf("Hello World %d!\n", i);
  }
  do {
    i++;
  } while (1);
}

int main(void) {
    // call configure flash so that the processor can load the insturctions it need before running the clk so fast
    configureFlash();

    // set up overall clock for overall 
    configureClock();

    //configure clocks for rcc, gpio, flash, interrupts, timers
    // turn on clock source for TIM15 (bit 16 is for TIM15)
    RCC->APB2ENR |= 1 << 16;
    // turn on clock source for TIM16 (bit 17 is for TIM16)
    RCC->APB2ENR |= 1 << 17;
    // turn on clock source for GPIOA (bit 0 is for A)
    RCC->AHB2ENR |= (1 << 0);
    // turn on clock sources for EXTI, NVIC, and SYSCFG ???but exti and nvic don't need them?
    RCC->APB2ENR |= (1 << 0); //Syscfg

    //initialize everything
    // initialize GPIO pins
    pinMode(A_PIN, GPIO_INPUT);
    pinMode(B_PIN, GPIO_INPUT);

    //initialize interrupts
    __enable_irq();
    initInterrupt(A_PIN);
    initInterrupt(B_PIN);

    //initialize timers
    initTIM1516(TIM16); //init for pulse counting
    initTIM1516(TIM15); //init for print delaying

    //calculate velocity
    volatile float velocity = 0.0;
    volatile float direction = -1.0;
    

    while(1){
      // update velocity
      velocity = update_velocity();
      direction = update_direction();

      //print velocity
      printf("%f rev/s\n", velocity);
      //printf("hi");

      //delay 0.1 s (updates at 1 Hz)
      delay_millis1516(TIM16, 500);
      
    }


}

int test2main(void){
    configureFlash();
    configureClock();

    RCC->APB2ENR |= 1 << 16; //tim15
   
    RCC->APB2ENR |= 1 << 17;//tim16

    RCC->AHB2ENR |= (1 << 0);//gpioa

    RCC->APB2ENR |= (1 << 0); //Syscfg

    //initialize everything
    // initialize GPIO pins
    pinMode(A_PIN, GPIO_INPUT);
    pinMode(B_PIN, GPIO_INPUT);

    //initialize interrupts
    __enable_irq();
    initInterrupt(A_PIN);
    initInterrupt(B_PIN);

    //initialize timers
    initTIM1516(TIM16);

    while(1){
      
      togglePin(3);

      //delay 0.1 s (updates at 1 Hz)
      delay_millis1516(TIM16, 500);
      
    }


}




/*************************** End of file ****************************/
