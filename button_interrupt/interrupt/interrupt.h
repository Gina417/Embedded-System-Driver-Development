/* This file manages the module header files for main.c. 
*  If any peripheral is used in main.c, include all its header files here.
*/

#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#include "module.h"

typedef void (*ISR_Callback_t)(void);

void EXTI0_IRQ_Callback(ISR_Callback_t callback);

#endif