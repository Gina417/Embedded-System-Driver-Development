#ifndef _RCC_H
#define _RCC_H

#include <stdint.h>

#include "stm32f407.h"

/* RCC AHB1 peripheral definition */
#define RCC_AHB1_GPIOA      (1 << 0) // GPIOA clock enable and reset
#define RCC_AHB1_GPIOB      (1 << 1) // GPIOB clock enable and reset
#define RCC_AHB1_GPIOC      (1 << 2) // GPIOC clock enable and reset
#define RCC_AHB1_GPIOD      (1 << 3) // GPIOD clock enable and reset
#define RCC_AHB1_GPIOE      (1 << 4) // GPIOE clock enable and reset
#define RCC_AHB1_GPIOF      (1 << 5) // GPIOF clock enable and reset
#define RCC_AHB1_GPIOG      (1 << 6) // GPIOG clock enable and reset
#define RCC_AHB1_GPIOH      (1 << 7) // GPIOH clock enable and reset
#define RCC_AHB1_GPIOI      (1 << 8) // GPIOI clock enable and reset
#define RCC_AHB1_CRC        (1 << 12) // CRC clock enable and reset
#define RCC_AHB1_BKPSRAM    (1 << 18) // BKPSRAM clock enable
#define RCC_AHB1_CCMDATARAM (1 << 20) // CCMDATARAM clock enable
#define RCC_AHB1_DMA1       (1 << 21) // DMA1 clock enable and reset
#define RCC_AHB1_DMA2       (1 << 22) // DMA2 clock enable and reset
#define RCC_AHB1_ETHMAC     (1 << 25) // ETHMAC clock enable
#define RCC_AHB1_ETHMACTX   (1 << 26) // ETHMACTX clock enable
#define RCC_AHB1_ETHMACRX   (1 << 27) // ETHMACRX clock enable
#define RCC_AHB1_ETHMACPTP  (1 << 28) // ETHMACPTP clock enable
#define RCC_AHB1_OTGHS      (1 << 29) // OTGHS clock enable and reset
#define RCC_AHB1_OTGHSULPI  (1 << 30) // OTGHSULPI clock enable


/* Check whether the peripheral is valid under control of the RCC_AHB1ENR register*/
static inline uint32_t Is_RCC_AHB1ENR_PERITH(uint32_t peripheral)
{
    return ( (peripheral & 0x7E7411FF) && (peripheral != 0) ); // 0x818BEE00 = (0b 0111 1110 0111 0100 0001 0001 1111 1111)
}

/* Check whether the peripheral is valid under control by the RCC_AHB1RSTR register*/
static inline uint32_t Is_RCC_AHB1RSTR_PERITH(uint32_t peripheral)
{
    return ( (peripheral & 0x226011FF) && (peripheral != 0)); // 0x226011FF = (0b 0010 0010 0110 0000 0001 0001 1111 1111)
}

void RCC_AHB1_ClkCtrl(uint32_t periphral, State_t state);
void RCC_AHB1_Reset(uint32_t periphral);

#endif