#include "syscfg.h"

/************************************************************
 * @fn     - GPIOx_to_SYSCFG_transfer
 * 
 * @brief  - Transfer base arress of GPIO port to SYSCFG data
 * 
 * @param  - pGPIOx: pointer to GPIO peripheral
 * 
 * @return - bit data (uint32_t)
 * 
 * GPIOA_BASEADDR = 0x40020000 = 0b 0100 0000 0000 0010 0000 0000 0000 0000 => 0000
 * GPIOB_BASEADDR = 0x40020400 = 0b 0100 0000 0000 0010 0000 0100 0000 0000 => 0001 
 * .
 * .
 * .
 * GPIOI_BASEADDR = 0x40022000 = 0b 0100 0000 0000 0010 0010 0000 0000 0000 => 1000
 * 
 */
uint32_t GPIOx_to_SYSCFG_transfer(GPIO_RegDef_t *pGPIOx)
{
    return ( ((uint32_t) pGPIOx >> 10) & 0xF);
}


/************************************************************
 * @fn     - SYSCFG_EXTI_Config
 * 
 * @brief  - Initialize the SYSCFG peripheral to configure the EXTI line
 * 
 * @param  - exri_line: EXTI line number (i.e. pin)
 * @param  - pGPIOx: pointer to GPIO peripheral
 * 
 * @return - none
 * 
 * 
 */
void SYSCFG_EXTI_Config(uint8_t exti_line, GPIO_RegDef_t *pGPIOx)
{
    uint32_t EXTICR_reg_num             = exti_line >> 2; // pin / 4
    uint32_t bit_offset                 = (exti_line & 0x3) << 2; // (pin % 4) * 4
    SYSCFG -> EXTICR[EXTICR_reg_num]    |= GPIOx_to_SYSCFG_transfer(pGPIOx) << bit_offset;
}