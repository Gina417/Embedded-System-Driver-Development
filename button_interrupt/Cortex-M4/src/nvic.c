#include "ppb.h"
#include "nvic.h"

#define VECTKEY ((uint32_t) 0x05FA0000) // VECTKEY value for the NVIC_VTOR register

/*******************************************************
 * @fn     - NVIC_IRQ_Enable
 * 
 * @brief  - Enable the interrupt request
 * 
 * @param  - *pNVICHandle: pointer to NVIC_Handle_t structure
 * 
 * @return - none
 * 
 */

void NVIC_IRQ_Enable(NVIC_Handle_t *pNVICHandle)
{
    if ( pNVICHandle == (void *)0 || !Is_valid_IRQn(pNVICHandle -> IRQ_number) || !Is_valid_PriorityNum(pNVICHandle -> Gpriority) || !Is_valid_PriorityNum(pNVICHandle -> Spriority) ) {
        // error handling
        return; 
    }

    if (pNVICHandle -> IRQ_number < 32){
        NVIC -> ISER[0] |= (1 << pNVICHandle -> IRQ_number);
    }
    else if ( (pNVICHandle -> IRQ_number >= 32) && (pNVICHandle -> IRQ_number < 64) ){
        NVIC -> ISER[1] |= (1 << (pNVICHandle -> IRQ_number & 0x1F)); // IRQ_number & 0x1F = IRQ_number % 32, 0x1F = 31
    }
    else if ( (pNVICHandle -> IRQ_number >= 64) && (pNVICHandle -> IRQ_number < 96) ){
        NVIC -> ISER[2] |= (1 << (pNVICHandle -> IRQ_number & 0x3F)); // IRQ_number & 0x3F = IRQ_number % 64, 0x3F = 63
    }
}


/*******************************************************
 * @fn     - NVIC_IRQ_Disable
 * 
 * @brief  - Disable the interrupt request
 * 
 * @param  - *pNVICHandle: pointer to NVIC_Handle_t structure
 * 
 * @return - none
 * 
 */

void NVIC_IRQ_Disable(NVIC_Handle_t *pNVICHandle)
{
    if (pNVICHandle -> IRQ_number < 32){
        NVIC -> ICER[0] |= (1 << pNVICHandle -> IRQ_number);
    }
    else if ( (pNVICHandle -> IRQ_number >= 32) && (pNVICHandle -> IRQ_number < 64) ){
        NVIC -> ICER[1] |= (1 << (pNVICHandle -> IRQ_number & 0x1F)); // IRQ_number & 0x1F = IRQ_number % 32, 0x1F = 31
    }
    else if ( (pNVICHandle -> IRQ_number >= 64) && (pNVICHandle -> IRQ_number < 96) ){
        NVIC -> ICER[2] |= (1 << (pNVICHandle -> IRQ_number & 0x3F)); // IRQ_number & 0x3F = IRQ_number % 64, 0x3F = 63
    }
}


/*******************************************************
 * @fn     - NVIC_PrioityGroupConfig
 * 
 * @brief  - Tell the NVIC how to split the priority bits
 * 
 * @param  - group_type: group priority and sub-priority
 * 
 * @return - none
 * 
 */

void NVIC_PrioityGroupConfig(PriorityGroup_t group_type)
{
    if ( !Is_valid_PriorityGroup(group_type) ){
        // error handling
        return; 
    }
    
    SCB2 -> AIRCR = (VECTKEY | group_type); // set the VECTKEY and group priority 
}


/*******************************************************
 * @fn     - NVIC_SetPriority
 * 
 * @brief  - Set the group priority and sub-priority of the interrupt request
 * 
 * @param  - *pNVICHandle: pointer to NVIC_Handle_t structure
 * 
 * @return - none
 * 
 * 
 *  (left) shift   GP bits   SP bits   right shift
 *        0           4         0           4
 *        1           3         1           3
 *        2           2         2           2
 *        3           1         3           1
 *        4           0         4           0
 * 
 */

void NVIC_SetPriority(NVIC_Handle_t *pNVICHandle)
{
    uint8_t gpshift = ( (SCB2 -> AIRCR & 0x700) >> 0x8 ) - 0x3; // get the group priority shift value
    uint8_t tmp = (uint8_t)(pNVICHandle -> Gpriority << gpshift) | (pNVICHandle -> Spriority & (0x0F >> (4 - gpshift))); // calculate the priority value (put in the least 4 bits)
    NVIC -> IPR[pNVICHandle -> IRQ_number] = tmp << 4; // shift the priority value to the left by 4 bits
}


