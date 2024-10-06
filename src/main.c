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

#define A_PIN 8
#define B_PIN 10

int main(void) {
    // call configure flash so that the processor can load the insturctions it need before running the clk so fast
    configureFlash();

    // set up overall clock for overall 
    configureClock();

    //configure clocks for rcc, gpio, flash, interrupts, timers
    // turn on clock source for TIM15 (bit 16 is for TIM15)
    RCC->APB2ENR |= 1 << 16;
    // turn on clock source for GPIOA (bit 0 is for A)
    RCC->AHB2ENR |= (1 << 0);
    // turn on clock sources for EXTI, NVIC, and SYSCFG ???but exti and nvic don't need them?
    RCC->APB2ENR |= (1 << 0) //Syscfg

    //initialize everything
    // initialize GPIO pins
    pinMode(A_PIN, GPIO_INPUT);
    pinMode(B_PIN, GPIO_INPUT);

    //initialize interrupts
    __enable_irq();
    initInterrupt(A_PIN);
    initInterrupt(B_PIN);

    //initialize timer
    initTIM1516(TIM15);

    //calculate velocity
    volatile float velocity;
    volatile float direction;
    

    while(1){
      // update velocity
      velocity = update_velocity();
      direction = update_direction();

      //print velocity
      printf("%d revs/min", velocity);

      //delay 0.1 s (updates at 10 Hz)
      delay_millis1516(TIM15, 100);
      
    }


}

/*************************** End of file ****************************/
