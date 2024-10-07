// STM32L432KC_GPIO.h
// Header for GPIO functions

#ifndef STM32L4_GPIO_H
#define STM32L4_GPIO_H

#include <stdint.h> // Include stdint header
#include <stm32l432xx.h> //include device header to get all the nice structs for the stm32l432kc


///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Values for GPIO pins ("val" arguments)
#define GPIO_LOW    0
#define GPIO_HIGH   1

// Base addresses for GPIO ports
//#define GPIOB_BASE  (0x48000400UL)

// Arbitrary GPIO functions for pinMode()
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_ALT    2
#define GPIO_ANALOG 3

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for GPIO
///////////////////////////////////////////////////////////////////////////////

// GPIO register structs here


// Pointers to GPIO-sized chunks of memory for each peripheral
//#define GPIOB ((GPIO *) GPIOB_BASE)

#define GPIO GPIOA

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void pinMode(int pin, int function);

int digitalRead(int pin);

void digitalWrite(int pin, int val);

void togglePin(int pin);

#endif