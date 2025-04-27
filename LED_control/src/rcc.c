#include "stm32f407.h"
#include "rcc.h"

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
