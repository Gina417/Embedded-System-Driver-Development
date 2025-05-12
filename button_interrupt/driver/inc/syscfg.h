#ifndef _SYSCFG_H
#define _SYSCFG_H

#include "stm32f407.h" 
#include "gpio.h"

void SYSCFG_EXTI_Config(uint8_t exti_line, GPIO_RegDef_t *pGPIOx);

#endif