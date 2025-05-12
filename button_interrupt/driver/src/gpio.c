#include "stm32f407.h"
#include "rcc.h"
#include "gpio.h"
#include "exti.h"
#include "syscfg.h"
#include "ppb.h"

/*******************************************************
 * @fn     - GPIO_Init
 * 
 * @brief  - Initialize the GPIO peripheral
 * 
 * @param  - pGPIOHandle: pointer to GPIO_Handle_t structure
 * 
 * @return - none
 * 
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    // ensure that the parameters are valid
    if ( pGPIOHandle == (void *)0 || !Is_valid_GPIO_PERIPH(pGPIOHandle -> pGPIOx) || !Is_valid_GPIO_PIN(pGPIOHandle -> pin) || !Is_valid_GPIO_MODE(pGPIOHandle -> mode) || !Is_valid_GPIO_OTYPE(pGPIOHandle -> otype) || !Is_valid_GPIO_OSPEED(pGPIOHandle -> ospeed) || !Is_valid_GPIO_PUPD(pGPIOHandle -> pupd) ) {
        // error handling
        return; 
    }

    /* if GPIO mode is not in EXTI mode */
    if (!Is_GPIO_EXTI_MODE(pGPIOHandle -> mode)){
        pGPIOHandle -> pGPIOx -> MODER   &= ~(0x3 << (2 * pGPIOHandle -> pin));
        pGPIOHandle -> pGPIOx -> MODER   |= (pGPIOHandle -> mode << (2 * pGPIOHandle -> pin));
    }
    /* if GPIO is in EXTI mode */
    else{
        /* Interrupt configuration */
        /* 1. enable APB2 clock */
        RCC_APB2_ClkCtrl(RCC_APB2_SYSCFG, ENABLE);

        /* 2. configure SYSCFG_EXTICR register */
        SYSCFG_EXTI_Config(pGPIOHandle -> pin, pGPIOHandle -> pGPIOx);

        /* 3. configure EXTI registers */
        EXTI_Handle_t exti_handle = {
            .exti_line      = pGPIOHandle -> pin,
            .exti_mode      = ITR,    // Hardware interrupt
            .trigger_mode   = (EXTI_TrigMode_t)(pGPIOHandle -> mode)
        };

        /* 4. initialize EXTI */
        EXTI_Config(&exti_handle);
    }

    /* set the outpu type */
    // 1. reset 
    pGPIOHandle -> pGPIOx -> OTYPER  &= ~(0x1 << pGPIOHandle -> pin);
    // 2. set
    pGPIOHandle -> pGPIOx -> OTYPER  |= (pGPIOHandle -> otype << pGPIOHandle -> pin);

    /* set the output speed */
    pGPIOHandle -> pGPIOx -> OSPEEDR &= ~(0x3 << (2 * pGPIOHandle -> pin));
    pGPIOHandle -> pGPIOx -> OSPEEDR |= (pGPIOHandle -> ospeed << (2 * pGPIOHandle -> pin));
      
    /* set the pull-up/pull-down resistor */
    pGPIOHandle -> pGPIOx -> PUPDR   &= ~(0x3 << (2 * pGPIOHandle -> pin));                                                                                                                                                                                                           
    pGPIOHandle -> pGPIOx -> PUPDR   |= (pGPIOHandle -> pupd << (2 * pGPIOHandle -> pin));
}


/*******************************************************
 * @fn     - GPIO_DeInit
 * 
 * @brief  - De-initialize (reset) the GPIO peripheral 
 * 
 * @param  - pGPIOx: pointer to GPIO peripheral
 * 
 * @return - none
 * 
 */

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
