#ifndef _EXTI_H_
#define _EXTI_H_

#include <stdint.h>
#include "stm32f407.h"
#include "gpio.h"

typedef enum {
    ITR = 0x1,     // Interrupt mode
    EVT = 0x2      // Event mode
}EXTI_Mode_t;

typedef enum {
    RISE_TRIG       = 0x4,      // rising edge trigger
    FALL_TRIG       = 0x5,      // falling edge trigger
    RISE_FALL_TRIG  = 0x6       // rising and falling edge trigger
}EXTI_TrigMode_t;

typedef struct{
    uint32_t        exti_line;      // EXTI line number (i.e. pin)
    EXTI_Mode_t     exti_mode;      // Interrupt or event mode
    EXTI_TrigMode_t trigger_mode;   // Trigger mode (rising, falling, or both)
}EXTI_Handle_t;

/* Check the validity of EXTI initialization */
static inline uint32_t Is_valid_EXTI_Line(uint32_t exti_line)
{
    return ( (exti_line >= 0) && (exti_line <= 22) );
}
static inline uint32_t Is_valid_EXTI_Mode(EXTI_Mode_t mode)
{
    return ( (mode == ITR) || (mode == EVT) );
}
static inline uint32_t Is_valid_EXTI_Trigger(EXTI_TrigMode_t trigger_mode)
{
    return ( (trigger_mode == RISE_TRIG) || (trigger_mode == FALL_TRIG) || 
             (trigger_mode == RISE_FALL_TRIG) );
}

void EXTI_Config(EXTI_Handle_t *pEXTIHandle);
void EXTI_ClearPending(uint32_t exti_line);

#endif