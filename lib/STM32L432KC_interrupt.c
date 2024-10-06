// STM32L432KC_interrupt.c
// Source code for interrupt functions

#include "STM32L432KC_interrupt.h"

///////////////////////////////////////////////////////////////////////////////
// Variables
///////////////////////////////////////////////////////////////////////////////
volatile int last_A_rising_edge;
volatile int last_B_rising_edge;
volatile int last_A_falling_edge;
volatile int last_B_falling_edge;

volatile int current_A_state;
volatile int current_B_state;





void initInterrupt(int pin_num){
  //map GPIO to an exti line in exti mux
  SYSCFG->EXTICR[pin_num / 4] &= 0b000 << ((pin_num % 4) *4); //exticr is a list, there are 4 registers per list and their bits are 2:0, 6:4, 10:8, 14:12

  // config exti input mask register
  EXTI->IMR1 |= 1 << pin_num;

  //config rising and falling triggers to generate interrupts
  EXTI->RTSR1 |= 1 << pin_num;
  EXTI->FTSR1 |= 1 << pin_num;

  
  //config NVIC to accept GPIO
  // this info comes from the ARM Reference Manual, not the STM32L432 rm
  if ((pin_num >= 10) & (pin_num <= 15)){
    NVIC->ISER[1] |= 1 << (EXTI15_10_IRQn - 32);  //set the first register of the list of register values to 40 in order to enable exti 15-10???????
  } 
  else if ((pin_num >= 5) & (pin_num <= 9)){
    NVIC->ISER[0] |= 1 << EXTI9_5_IRQn; //set the first register of the list of register to 23 in order to enable exti 9-5
  }
  

}

void EXTI9_5_IRQHandler(void){
  // check if triggered on rising or falling
  if (current_A_state == 0){ // rising 0 to 1
    // if rising on A, reset counter
    TIM15->EGR |= 1;
  }
  else {
    // if falling on A, note time and use it to update velocity
    last_A_falling_edge = TIM15->CNT;
  }
  
  // clear the interrupt
  EXTI->PR1 |= (1 << 8);
  // look for next edge
  current_A_state = ~current_A_state;
  

}

void EXTI15_10_IRQHandler(void){
  if (current_B_state == 0){
   // if rising on B, note when it rose
    last_B_rising_edge = TIM15->CNT;
  }
  else{
    // if falling on B, subtract current time from time of rising edge and update velocity
    last_B_falling_edge = TIM15->CNT;
  }
 
  //clear the interrupt
  EXTI->PR1 |= (1 << 10);
  //look for next edge
  current_B_state = ~current_B_state;

}

float update_velocity(void){
  float avg_period = ((last_A_falling_edge) + (last_B_falling_edge-last_B_rising_edge)) / 2.0;
  float vel = avg_period * SystemCoreClock * 120; // convert pulse count to seconds, 1 rev is 120 pulses
  return vel;
}

float update_direction(void){
  // clock resets on the A rising edge, diretion is determined by whether we see a B falling or rising edge next
  if (last_B_rising_edge > last_B_falling_edge) return 1;
  else return -1;
}

