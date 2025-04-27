#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>
#include "stm32f407.h"
#include "rcc.h"

/* GPIO mode type enumeration */
typedef enum {
    MODER_INPUT  = 0x00, // GPIO input mode
    MODER_OUTPUT = 0x01, // GPIO output mode
    MODER_AF     = 0x02, // GPIO alternate function mode
    MODER_ANALOG = 0x03  // GPIO analog mode
}MODER_t;

/* GPIO output type enumeration */
typedef enum {
    OTYPER_PP = 0x00, // GPIO output push-pull
    OTYPER_OD = 0x01  // GPIO output open-drain
}OTYPER_t;

/* GPIO speed type register */
typedef enum {
    OSPEEDR_LOW    = 0x00, // GPIO low speed
    OSPEEDR_MEDIUM = 0x01, // GPIO medium speed
    OSPEEDR_FAST   = 0x02, // GPIO fast speed
    OSPEEDR_HIGH   = 0x03  // GPIO high speed
}OSPEEDR_t;

/* GPIO pull-up/pull-down type register */
typedef enum {
    PUPDR_NONE  = 0x00, // GPIO no pull-up/pull-down
    PUPDR_UP    = 0x01, // GPIO pull-up
    PUPDR_DOWN  = 0x02  // GPIO pull-down
}PUPDR_t;

/* GPIO bit set and bit reset enumeration */
typedef enum {
    GPIO_PIN_SET   = 0x01, // GPIO bit set
    GPIO_PIN_RESET = 0x00  // GPIO bit reset
}GPIO_PIN_STATE_t;

typedef enum {
    GPIO_PIN_0  = 0,
    GPIO_PIN_1  = 1,
    GPIO_PIN_2  = 2,
    GPIO_PIN_3  = 3,
    GPIO_PIN_4  = 4,
    GPIO_PIN_5  = 5,
    GPIO_PIN_6  = 6,
    GPIO_PIN_7  = 7,
    GPIO_PIN_8  = 8,
    GPIO_PIN_9  = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15
}GPIO_PIN_t;

/* Handle structure for a GPIO pin */
typedef struct {
    GPIO_RegDef_t *pGPIOx; // Pointer to GPIO peripheral
    GPIO_PIN_t    pin; // GPIO pin number
    MODER_t       mode; // GPIO mode
    OTYPER_t      otype; // GPIO output type
    OSPEEDR_t     ospeed; // GPIO speed
    PUPDR_t       pupd; // GPIO pull-up/pull-down
}GPIO_Handle_t;

/* Clock enable inline fuctions for GPIO ports */
static inline void GPIOA_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOA, state); }
static inline void GPIOB_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOB, state); }
static inline void GPIOC_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOC, state); }
static inline void GPIOD_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOD, state); }
static inline void GPIOE_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOE, state); }
static inline void GPIOF_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOF, state); }
static inline void GPIOG_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOG, state); }
static inline void GPIOH_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOH, state); }
static inline void GPIOI_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOI, state); }
// static inline void GPIOJ_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOJ, state); }
// static inline void GPIOK_ClkCtrl(State_t state) { RCC_AHB1_ClkCtrl(RCC_AHB1_GPIOK, state); } 

/* Check the validity of the initialization */
/* GPIO Port*/
static inline uint8_t Is_valid_GPIO_PERIPH(GPIO_RegDef_t *pGPIOx){
    return ( (pGPIOx == GPIOA) || (pGPIOx == GPIOB) || (pGPIOx == GPIOC) || 
             (pGPIOx == GPIOD) || (pGPIOx == GPIOE) || (pGPIOx == GPIOF) ||
             (pGPIOx == GPIOG) || (pGPIOx == GPIOH) || (pGPIOx == GPIOI) );
}
/* GPIO Pin */
static inline uint8_t Is_valid_GPIO_PIN(GPIO_PIN_t pin){
    return ( (pin >= GPIO_PIN_0) && (pin <= GPIO_PIN_15) );
}
/* GPIO Mode*/
static inline uint8_t Is_valid_GPIO_MODE(MODER_t mode){
    return( (mode == MODER_INPUT) || (mode == MODER_OUTPUT) || 
            (mode == MODER_AF) || (mode == MODER_ANALOG) );
}
/* GPIO Otype */
static inline uint8_t Is_valid_GPIO_OTYPE(OTYPER_t otype){
    return ( (otype == OTYPER_PP) || (otype == OTYPER_OD) );
}
/* GPIO Ospeed */
static inline uint8_t Is_valid_GPIO_OSPEED(OSPEEDR_t ospeed){
    return ( (ospeed == OSPEEDR_LOW) || (ospeed == OSPEEDR_MEDIUM) ||
            (ospeed == OSPEEDR_FAST) || (ospeed == OSPEEDR_HIGH) );
}
/* GPIO pupd */
static inline uint8_t Is_valid_GPIO_PUPD(PUPDR_t pupd){
    return ( (pupd == PUPDR_NONE) || (pupd == PUPDR_UP) ||
            (pupd == PUPDR_DOWN) );
}

/* Init and De-init */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* Pin read and write */
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin); // return 0 or 1, so return type is uint8_t               
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin, GPIO_PIN_STATE_t new_state); // return 0 or 1, so return type is uint8_t

/* Toggle Pin */
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin); // return 0 or 1, so return type is uint8_t                                           


#endif