#include "interrupt.h"

// define callback type and global pointer to callback function
static ISR_Callback_t EXTI0_Callback = 0;

/*******************************************************
 * @fn     - EXTI0_IRQ_Callback
 * 
 * @brief  - Provides a function for EXTI line 0 to let the user register a callback in main function
 * 
 * @param  - callback: pointer to the callback function
 * 
 * @return - none
 * 
 */
void EXTI0_IRQ_Callback(ISR_Callback_t callback) {
    EXTI0_Callback = callback;
}

/*******************************************************
 * @fn     - EXTI0_IRQHandler
 * 
 * @brief  - Call the registered callback function and clear the pending bit of EXTI line 0 
 * 
 * @param  - none
 * 
 * @return - none
 * 
 */
void EXTI0_IRQHandler(void){

    // for (uint32_t i = 0; i < 500000/2; i++); // Delay for debouncing

    if (EXTI0_Callback) {
        EXTI0_Callback(); // Call the registered callback function
    }

    EXTI_ClearPending(IRQn_EXTI0); // Clear the pending bit for EXTI line 0
}