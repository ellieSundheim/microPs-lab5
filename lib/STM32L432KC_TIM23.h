// STM32L432KC_TIM23.h
// esundheim@hmc.edu, 9-27-24
// Header for TIM2 and functions

#ifndef STM32L432KC_TIM23_H
#define STM32L432KC_TIM23_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM2_BASE (0x40000000UL) 
#define TIM3_BASE (0x40000400UL)


typedef struct
{
  __IO uint32_t CR1;          /*!< TIM23 control register 1,                                              Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< TIM23 control register 2,                                              Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< TIM23 slave mode control register,                                     Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< TIM23 DMA interrupt enable register,                                   Address offset: 0x0C */
  __IO uint32_t SR;           /*!< TIM23 status register,                                                 Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< TIM23 event generation register                                        Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< TIM23 capture/compare mode register 1,                                 Address offset: 0x18 */
  __IO uint32_t CCMR2;        /*!< TIM23 capture/compare mode register 2,                                 Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< TIM23 capture/compare enable register,                                 Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< TIM23 counter register                                                 Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< TIM23 prescaler register,                                              Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< TIM23 auto reload register,                                            Address offset: 0x2C */
   uint32_t RESERVED;         /*!< Reserved,                                                             Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< TIM23 capture/compare register 1,                                      Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< TIM23 capture/compare register 2,                                      Address offset: 0x38 */
  __IO uint32_t CCR3;         /*!< TIM23 capture/compare register 3,                                      Address offset: 0x3C */
  __IO uint32_t CCR4;         /*!< TIM23 capture/compare register 4,                                      Address offset: 0x40 */
  uint32_t      RESERVED1;    /*!< Reserved,                                                             Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< TIM23 DMA control register,                                            Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< TIM23 DMA address for full transfer,                                   Address offset: 0x4C */
  __IO uint32_t OR1;          /*!< TIM23 option register 1,                                               Address offset: 0x50 */
  uint32_t RESERVED2;         /*!< Reserved,                                                             Address offset: 0x54 */
  uint32_t RESERVED3;         /*!< Reserved,                                                             Address offset: 0x58 */
  uint32_t RESERVED4;         /*!< Reserved,                                                             Address offset: 0x5C */
  __IO uint32_t OR2;          /*!< TIM23 option register 2,                                               Address offset: 0x60 */
} TIM23_TypeDef;

#define TIM2 ((TIM23_TypeDef *) TIM2_BASE)
#define TIM3 ((TIM23_TypeDef *) TIM3_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
void initTIM(TIM23_TypeDef * TIMx);
void initTIM_PWM(TIM23_TypeDef * TIMx);
void delay_millis(TIM23_TypeDef * TIMx, uint32_t ms);
void update_freq(TIM23_TypeDef* TIMx, uint32_t newFreq);



#endif