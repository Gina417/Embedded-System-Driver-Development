#ifndef _STM32F407_H
#define _STM32F407_H


#include <stdint.h>

// base addresses of AHBx & APBx 
#define AHB1_BASEADDR ((uint32_t) 0x40020000)
#define AHB2_BASEADDR ((uint32_t) 0x50000000)
#define AHB3_BASEADDR ((uint32_t) 0xA0000000)
#define APB1_BASEADDR ((uint32_t) 0x40000000)
#define APB2_BASEADDR ((uint32_t) 0x40010000)

/* AHB1 peripherals */
#define GPIOA_BASEADDR         (AHB1_BASEADDR + 0x0000)
#define GPIOB_BASEADDR         (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR         (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR         (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR         (AHB1_BASEADDR + 0x1000)
#define GPIOF_BASEADDR         (AHB1_BASEADDR + 0x1400)
#define GPIOG_BASEADDR         (AHB1_BASEADDR + 0x1800)
#define GPIOH_BASEADDR         (AHB1_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR         (AHB1_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR         (AHB1_BASEADDR + 0x2400)
#define GPIOK_BASEADDR         (AHB1_BASEADDR + 0x2800)
#define CRC_BASEADDR           (AHB1_BASEADDR + 0x3000)
#define RCC_BASEADDR           (AHB1_BASEADDR + 0x3800)
#define FLASHITF_BASEADDR      (AHB1_BASEADDR + 0x3C00)
#define BKPSRAM_BASEADDR       (AHB1_BASEADDR + 0x4000)
#define DMA1_BASEADDR          (AHB1_BASEADDR + 0x6000)
#define DMA2_BASEADDR          (AHB1_BASEADDR + 0x6400)
#define ETHMAC_BASEADDR        (AHB1_BASEADDR + 0x8000)
#define DMA2D_BASEADDR         (AHB1_BASEADDR + 0xB000)
#define OTGHS_BASEADDR         (AHB1_BASEADDR + 0x20000)

/* AHB2 peripherals */
#define OTGFS_BASEADDR         (AHB2_BASEADDR + 0x0000)
#define DCMI_BASEADDR          (AHB2_BASEADDR + 0x50000)
#define CRYP_BASEADDR          (AHB2_BASEADDR + 0x60000)
#define HASH_BASEADDR          (AHB2_BASEADDR + 0x60400)
#define RNG_BASEADDR           (AHB2_BASEADDR + 0x60800)

/* AHB3 peripherals */
#define FSMC_BASEADDR          (AHB3_BASEADDR + 0x0000)

/* APB1 periphrals */
#define TIM2_BASEADDR          (APB1_BASEADDR + 0x0000)
#define TIM3_BASEADDR          (APB1_BASEADDR + 0x0400)
#define TIM4_BASEADDR          (APB1_BASEADDR + 0x0800)
#define TIM5_BASEADDR          (APB1_BASEADDR + 0x0C00)
#define TIM6_BASEADDR          (APB1_BASEADDR + 0x1000)
#define TIM7_BASEADDR          (APB1_BASEADDR + 0x1400)
#define TIM12_BASEADDR         (APB1_BASEADDR + 0x1800)
#define TIM13_BASEADDR         (APB1_BASEADDR + 0x1C00)
#define TIM14_BASEADDR         (APB1_BASEADDR + 0x2000)
#define RTCBKP_BASEADDR        (APB1_BASEADDR + 0x2800)
#define WWDG_BASEADDR          (APB1_BASEADDR + 0x2C00)
#define IWDG_BASEADDR          (APB1_BASEADDR + 0x3000)
#define I2S2EXT_BASEADDR       (APB1_BASEADDR + 0x3400)
#define SPI2_BASEADDR          (APB1_BASEADDR + 0x3800)
#define SPI3_BASEADDR          (APB1_BASEADDR + 0x3C00)
#define I2S3EXT_BASEADDR       (APB1_BASEADDR + 0x4000)
#define USART2_BASEADDR        (APB1_BASEADDR + 0x4400)
#define USART3_BASEADDR        (APB1_BASEADDR + 0x4800)
#define UART4_BASEADDR         (APB1_BASEADDR + 0x4C00)
#define UART5_BASEADDR         (APB1_BASEADDR + 0x5000)
#define I2C1_BASEADDR          (APB1_BASEADDR + 0x5400)
#define I2C2_BASEADDR          (APB1_BASEADDR + 0x5800)
#define I2C3_BASEADDR          (APB1_BASEADDR + 0x5C00)
#define CAN1_BASEADDR          (APB1_BASEADDR + 0x6400)
#define CAN2_BASEADDR          (APB1_BASEADDR + 0x6800)
#define PWR_BASEADDR           (APB1_BASEADDR + 0x7000)
#define DAC_BASEADDR           (APB1_BASEADDR + 0x7400)
#define UART7_BASEADDR         (APB1_BASEADDR + 0x7800)
#define UART8_BASEADDR         (APB1_BASEADDR + 0x7C00)

/* APB2 peripherals */
#define TIM1_BASEADDR          (APB2_BASEADDR + 0x0000)
#define TIM8_BASEADDR          (APB2_BASEADDR + 0x0400)
#define USART1_BASEADDR        (APB2_BASEADDR + 0x1000)
#define USART6_BASEADDR        (APB2_BASEADDR + 0x1400)
#define ADC1_BASEADDR          (APB2_BASEADDR + 0x2000)
#define ADC2_BASEADDR          (APB2_BASEADDR + 0x2100)
#define ADC3_BASEADDR          (APB2_BASEADDR + 0x2200)
#define SDIO_BASEADDR          (APB2_BASEADDR + 0x2C00)
#define SPI1_BASEADDR          (APB2_BASEADDR + 0x3000)
#define SPI4_BASEADDR          (APB2_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR        (APB2_BASEADDR + 0x3800)
#define EXTI_BASEADDR          (APB2_BASEADDR + 0x3C00)
#define TIM9_BASEADDR          (APB2_BASEADDR + 0x4000)
#define TIM10_BASEADDR         (APB2_BASEADDR + 0x4400)
#define TIM11_BASEADDR         (APB2_BASEADDR + 0x4800)
#define SPI5_BASEADDR          (APB2_BASEADDR + 0x5000)
#define SPI6_BASEADDR          (APB2_BASEADDR + 0x5400)
#define SAI1_BASEADDR          (APB2_BASEADDR + 0x5800)
#define LTDC_BASEADDR          (APB2_BASEADDR + 0x6800)

/* GPIO base address definition */
#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*) GPIOI_BASEADDR)
// #define GPIOJ ((GPIO_RegDef_t *) GPIOJ_BASEADDR)
// #define GPIOK ((GPIO_RegDef_t *) GPIOK_BASEADDR)

/* RCC base address definition */
#define RCC ((RCC_RegDef_t*) RCC_BASEADDR)

/* periphral register definition structure for GPIO */
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile int32_t  BSRRL;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH; 
}GPIO_RegDef_t;

/* RCC register definition structure */
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t RESERVED0; 
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED1[2]; // 0x28-0x2C
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RESERVED3[2]; // 0x48-0x4C
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t RESERVED4;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RESERVED5[2]; // 0x68-0x6C
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RESERVED6[2]; // 0x78-0x7C
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

typedef enum {
    DISABLE = 0,
    ENABLE = 1
}State_t;

static inline uint32_t Is_valid_Function_State(State_t state) { return ( (state == ENABLE) || (state == DISABLE) ); }

#endif