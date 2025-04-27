#include "stm32f407.h"
#include "rcc.h"
#include "gpio.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    // ensure that the parameters are valid
    if ( pGPIOHandle == (void *)0 || 
         !Is_valid_GPIO_PERIPH(pGPIOHandle -> pGPIOx) ||
         !Is_valid_GPIO_PIN(pGPIOHandle -> pin) ||
         !Is_valid_GPIO_MODE(pGPIOHandle -> mode) ||
         !Is_valid_GPIO_OTYPE(pGPIOHandle -> otype) ||
         !Is_valid_GPIO_OSPEED(pGPIOHandle -> ospeed) ||
         !Is_valid_GPIO_PUPD(pGPIOHandle -> pupd) ) {
        // error handling
        return; 
    }

    /* reset the pin */ 
    pGPIOHandle -> pGPIOx -> MODER   &= ~(0x3 << (2 * pGPIOHandle -> pin));
    pGPIOHandle -> pGPIOx -> OTYPER  &= ~(0x1 << pGPIOHandle -> pin);
    pGPIOHandle -> pGPIOx -> OSPEEDR &= ~(0x3 << (2 * pGPIOHandle -> pin));  
    pGPIOHandle -> pGPIOx -> PUPDR   &= ~(0x3 << (2 * pGPIOHandle -> pin));                                                                                                                                                                                                           

    /* set the pin */
    pGPIOHandle -> pGPIOx -> MODER   |= (pGPIOHandle -> mode << (2 * pGPIOHandle -> pin));
    pGPIOHandle -> pGPIOx -> OTYPER  |= (pGPIOHandle -> otype << pGPIOHandle -> pin);
    pGPIOHandle -> pGPIOx -> OSPEEDR |= (pGPIOHandle -> ospeed << (2 * pGPIOHandle -> pin));
    pGPIOHandle -> pGPIOx -> PUPDR   |= (pGPIOHandle -> pupd << (2 * pGPIOHandle -> pin));
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    // ensure that the parameters are valid
    if (!Is_valid_GPIO_PERIPH(pGPIOx)){
        // error handling
        return; 
    }

    if (pGPIOx == GPIOA) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOA);
    }
    else if (pGPIOx == GPIOB) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOB);
    }
    else if (pGPIOx == GPIOC) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOC);
    }
    else if (pGPIOx == GPIOD) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOD);
    }
    else if (pGPIOx == GPIOE) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOE);
    }
    else if (pGPIOx == GPIOF) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOF);
    }
    else if (pGPIOx == GPIOG) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOG);
    }
    else if (pGPIOx == GPIOH) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOH);
    }
    else if (pGPIOx == GPIOI) {
        RCC_AHB1_Reset(RCC_AHB1_GPIOI);
    }
}

/*******************************************************
 * @fn     - GPIO_ReadPin
 * 
 * @brief  - Read the state of a pin of some GPIO port
 * 
 * @param  - pGPIOx: pointer to GPIO peripheral
 * @param  - pin: GPIO pin number
 * 
 * @return - 0 or 1
 * 
 */

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin)
{
    // ensure the parameters are valid
    if ( !Is_valid_GPIO_PERIPH(pGPIOx) || !Is_valid_GPIO_PIN(pin) ){
        return 0;
    }

    if ( (pGPIOx -> IDR >> pin) & 0x1 ) {
        return GPIO_PIN_SET;
    }
    else {
        return GPIO_PIN_RESET;
    }
} 

/*******************************************************
 * @fn     - GPIO_WritePin
 * 
 * @brief  - Write the state to a pin of some GPIO port
 * 
 * @param  - pGPIOx: pointer to GPIO peripheral
 * @param  - pin: GPIO pin number
 * @param  - new_state: new state of the pin
 * 
 * @return - none
 * 
 */

 void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin, GPIO_PIN_STATE_t new_state)
{
    // ensure the parameters are valid
    if ( !Is_valid_GPIO_PERIPH(pGPIOx) || !Is_valid_GPIO_PIN(pin) || 
         !Is_valid_Function_State(new_state) ){
        return;
    }

    if (new_state == GPIO_PIN_SET){
        pGPIOx -> BSRRL = (1 << pin);
    }
    else{
        pGPIOx -> BSRRL = (1 << (pin + 16));
    }
}

/*******************************************************
 * @fn     - GPIO_Toggle
 * 
 * @brief  - Toggle the pin of some GPIO port
 * 
 * @param  - pGPIOx: pointer to GPIO peripheral
 * @param  - pin: GPIO pin number
 * 
 * @return - none
 * 
 */

 void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_t pin)
{
    // ensure the parameters are valid
    if ( !Is_valid_GPIO_PERIPH(pGPIOx) || !Is_valid_GPIO_PIN(pin) ){
        return;
    }

    pGPIOx -> ODR ^= (1 << pin);
}
