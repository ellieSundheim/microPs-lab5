// STM32L432KC_TIM1516.h
// esundheim@hmc.edu, 9-27-24
// Header for TIM15/16 and functions

#ifndef STM32L432KC_TIM1516_H
#define STM32L432KC_TIM1516_H

#include <stdint.h>
#include <stm32l432xx.h> //include device header to get all the nice structs for the stm32l432kc


///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
//#define TIM15_BASE (0x40014000UL) 
//#define TIM16_BASE (0x40014400UL)

//note that TIM16 doesn't actually have a CCR2, so treat that as res for TIM16

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
void initTIM1516(TIM_TypeDef * TIMx);

void delay_millis1516(TIM_TypeDef * TIMx, uint32_t ms);




#endif