// STM32L432KC_TIM1516.h
// esundheim@hmc.edu, 9-27-24
// Header for TIM15/16 and functions

#ifndef STM32L432KC_TIM1516_H
#define STM32L432KC_TIM1516_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM15_BASE (0x40014000UL) 
#define TIM16_BASE (0x40014400UL)

//note that TIM16 doesn't actually have a CCR2, so treat that as res for TIM16

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
  __IO uint32_t RCR;         /*!< TIM15 RCR,                                                             Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< TIM23 capture/compare register 1,                                      Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< TIM23 capture/compare register 2,                                      Address offset: 0x38 */
  uint32_t RESERVED1;         /*!< TIM23 capture/compare register 3,                                      Address offset: 0x3C */
  uint32_t RESERVED2;         /*!< TIM23 capture/compare register 4,                                      Address offset: 0x40 */
  __IO uint32_t BDTR;    /*!< Reserved,                                                             Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< TIM23 DMA control register,                                            Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< TIM23 DMA address for full transfer,                                   Address offset: 0x4C */
  __IO uint32_t OR1;          /*!< TIM23 option register 1,                                               Address offset: 0x50 */
  uint32_t RESERVED3;         /*!< Reserved,                                                             Address offset: 0x54 */
  uint32_t RESERVED4;         /*!< Reserved,                                                             Address offset: 0x58 */
  uint32_t RESERVED5;         /*!< Reserved,                                                             Address offset: 0x5C */
  __IO uint32_t OR2;          /*!< TIM23 option register 2,                                               Address offset: 0x60 */
} TIM1516_TypeDef;

#define TIM15 ((TIM1516_TypeDef *) TIM15_BASE)
#define TIM16 ((TIM1516_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
void initTIM1516(TIM1516_TypeDef * TIMx);

void delay_millis1516(TIM1516_TypeDef * TIMx, uint32_t ms);




#endif