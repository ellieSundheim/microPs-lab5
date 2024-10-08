// STM32L432KC_EXTI.h
// Header for EXTI functions

#ifndef STM32L4_EXTI_H
#define STM32L4_EXTI_H

#include <stdint.h> // Include stdint header

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Base addresses for EXTI port
#define EXTI_BASE  (0x40010400UL)

// Pointers to GPIO-sized chunks of memory for each peripheral
#define EXTI ((EXTI *) EXTI_BASE)


///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initEXTI(void);

#endif