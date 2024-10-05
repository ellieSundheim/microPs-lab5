// STM32L432KC_interrupt.h
// Header for interrupt functions

#ifndef STM32L4_INTERRUPT_H
#define STM32L4_INTERRUPT_H

#include <stdint.h> // Include stdint header
#include <stm32l432xx.h> //include device header to get all the nice structs for the stm32l432kc
#include <system_stm32l4xx.h> //include this header too for ARM structs


///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initInterrupt(int pin_num);

#endif