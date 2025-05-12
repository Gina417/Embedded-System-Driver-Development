#include "stm32f407.h"
#include "rcc.h"

/*******************************************************
 * @fn     - RCC_AHB1_ClkCtrl
 * 
 * @brief  - Enable or disable the peripheral clock of AHB1
 * 
 * @param  - periphral: peripheral to enable or disable
 * @param  - state: ENABLE or DISABLE
 * 
 * @return - none
 * 
 */

void RCC_AHB1_ClkCtrl(uint32_t periphral, State_t state)
{
    // ensure that the parameters are valid
    if ( !Is_RCC_AHB1ENR_PERITH(periphral) || !Is_valid_Function_State(state) ){
        // error handling
        return; 
    }


    if (state == ENABLE){
        RCC -> AHB1ENR |= periphral;
    }
    else{
        RCC -> AHB1ENR &= ~periphral;
    }
}


/*******************************************************
 * @fn     - RCC_AHB1_Reset
 * 
 * @brief  - Reset the peripheral clock of AHB1
 * 
 * @param  - periphral: peripheral to reset
 * 
 * @return - none
 * 
 */

void RCC_AHB1_Reset(uint32_t periphral)
{
    // ensure that the parameters are valid
    if (!Is_RCC_AHB1RSTR_PERITH(periphral)){
        // error handling
        return; 
    }

    // reset the peripheral clock
    RCC -> AHB1RSTR |= periphral;
    
    // set the peripheral clock (the registers cannot always be reset)
    RCC -> AHB1RSTR &= ~periphral;

}

/*******************************************************
 * @fn     - RCC_APB2_ClkCtrl
 * 
 * @brief  - Enable or disable the peripheral clock of APB2
 * 
 * @param  - periphral: peripheral to enable or disable
 * @param  - state: ENABLE or DISABLE
 * 
 * @return - none
 * 
 */


void RCC_APB2_ClkCtrl(uint32_t periphral, State_t state)
{
    // ensure that the parameters are valid
    if ( !Is_RCC_APB2ENR_PERITH(periphral) || !Is_valid_Function_State(state) ){
        // error handling
        return; 
    }


    if (state == ENABLE){
        RCC -> APB2ENR |= periphral;
    }
    else{
        RCC -> APB2ENR &= ~periphral;
    }
}


/*******************************************************
 * @fn     - RCC_APB2_Reset
 * 
 * @brief  - Reset the peripheral clock of APB2
 * 
 * @param  - periphral: peripheral to reset
 * 
 * @return - none
 * 
 */

void RCC_APB2_Reset(uint32_t periphral)
{
    // ensure that the parameters are valid
    if (!Is_RCC_APB2RSTR_PERITH(periphral)){
        // error handling
        return; 
    }

    // reset the peripheral clock
    RCC -> APB2RSTR |= periphral;
    
    // set the peripheral clock (the registers cannot always be reset)
    RCC -> APB2RSTR &= ~periphral;

}
