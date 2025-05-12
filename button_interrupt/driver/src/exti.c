#include "exti.h"

/*******************************************************
 * @fn     - EXTI_Config
 * 
 * @brief  - Configure the EXTI peripheral
 * 
 * @param  - pEXTIHandle: pointer to EXTI_Handle_t structure
 * 
 * @return - none
 * 
 */

void EXTI_Config(EXTI_Handle_t *pEXTIHandle)
{
    if ( pEXTIHandle == (void *)0 || 
         !Is_valid_EXTI_Line(pEXTIHandle -> exti_line) ||
         !Is_valid_EXTI_Mode(pEXTIHandle -> exti_mode) ||
         !Is_valid_EXTI_Trigger(pEXTIHandle -> trigger_mode) ) {
        // error handling
        return; 
    }
    
    /* enable the exti interrupt/event */
    if (pEXTIHandle -> exti_mode == ITR){
        EXTI -> IMR |= (1 << pEXTIHandle -> exti_line);
    }
    else if (pEXTIHandle -> exti_mode == EVT){
        EXTI -> EMR |= (1 << pEXTIHandle -> exti_line);
    }

    /* set the trigger mode of EXTI */
    if (pEXTIHandle -> trigger_mode == RISE_TRIG){
        EXTI -> RTSR &= ~(1 << pEXTIHandle -> exti_line);
        EXTI -> RTSR |= (1 << pEXTIHandle -> exti_line);
    }
    else if (pEXTIHandle -> trigger_mode == FALL_TRIG){
        EXTI -> FTSR &= ~(1 << pEXTIHandle -> exti_line);
        EXTI -> FTSR |= (1 << pEXTIHandle -> exti_line);
    }
    else if (pEXTIHandle -> trigger_mode == RISE_FALL_TRIG){
        // 1. configure the FTSR and RTSR register
        EXTI -> FTSR |= (1 << pEXTIHandle -> exti_line);
        EXTI -> RTSR |= (1 << pEXTIHandle -> exti_line);
    }
    
}


/*******************************************************
 * @fn     - EXTI_ClearPending
 * 
 * @brief  - Clear the pending bit of EXTI line
 * 
 * @param  - exti_line: EXTI line number
 * 
 * @return - none
 * 
 */

void EXTI_ClearPending(uint32_t exti_line)
{
    if (!Is_valid_EXTI_Line(exti_line)){
        return;
    }

    EXTI -> PR |= (1 << exti_line);
}