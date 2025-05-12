#ifndef _STM32F407_H
#define _STM32F407_H


#include <stdint.h>

/* Interrupt request number definition */
typedef enum {
    IRQn_WWDG                   = 0,
    IRQn_PVD                    = 1,
    IRQn_TAMP_STAMP             = 2,
    IRQn_RTC_WKUP               = 3,
    IRQn_FLASH                  = 4,
    IRQn_RCC                    = 5,
    IRQn_EXTI0                  = 6,
    IRQn_EXTI1                  = 7,
    IRQn_EXTI2                  = 8,
    IRQn_EXTI3                  = 9,
    IRQn_EXTI4                  = 10,
    IRQn_DMA1_STREAM0           = 11,
    IRQn_DMA1_STREAM1           = 12,
    IRQn_DMA1_STREAM2           = 13,
    IRQn_DMA1_STREAM3           = 14,
    IRQn_DMA1_STREAM4           = 15,
    IRQn_DMA1_STREAM5           = 16,
    IRQn_DMA1_STREAM6           = 17,
    IRQn_ADC                    = 18,
    IRQn_CAN1_TX                = 19,
    IRQn_CAN1_RX0               = 20,
    IRQn_CAN1_RX1               = 21,
    IRQn_CAN1_SCE               = 22,
    IRQn_EXTI9_5                = 23,
    IRQn_TIM1_BRK_TIM9          = 24,
    IRQn_TIM1_UP_TIM10          = 25,
    IRQn_TIM1_TRG_COM_TIM11     = 26,
    IRQn_TIM1_CC                = 27,
    IRQn_TIM2                   = 28,
    IRQn_TIM3                   = 29,
    IRQn_TIM4                   = 30,
    IRQn_I2C1_EV                = 31,
    IRQn_I2C1_ER                = 32,
    IRQn_I2C2_EV                = 33,
    IRQn_I2C2_ER                = 34,
    IRQn_SPI1                   = 35,
    IRQn_SPI2                   = 36,
    IRQn_USART1                 = 37,
    IRQn_USART2                 = 38,
    IRQn_USART3                 = 39,
    IRQn_EXTI15_10              = 40,
    IRQn_RTC_ALARM              = 41,
    IRQn_OTG_FS_WKUP            = 42,
    IRQn_TIM8_BRK_TIM12         = 43,
    IRQn_TIM8_UP_TIM13          = 44,
    IRQn_TIM8_TRG_COM_TIM14     = 45,
    IRQn_TIM8_CC                = 46,
    IRQn_DMA1_STREAM7           = 47,
    IRQn_FSMC                   = 48,
    IRQn_SDIO                   = 49,
    IRQn_TIM5                   = 50,
    IRQn_SPI3                   = 51,
    IRQn_UART4                  = 52,
    IRQn_UART5                  = 53,
    IRQn_TIM6_DAC               = 54,
    IRQn_TIM7                   = 55,
    IRQn_DMA2_STREAM0           = 56,
    IRQn_DMA2_STREAM1           = 57,
    IRQn_DMA2_STREAM2           = 58,
    IRQn_DMA2_STREAM3           = 59,
    IRQn_DMA2_STREAM4           = 60,
    IRQn_ETH                    = 61,
    IRQn_ETH_WKUP               = 62,
    IRQn_CAN2_TX                = 63,
    IRQn_CAN2_RX0               = 64,
    IRQn_CAN2_RX1               = 65,
    IRQn_CAN2_SCE               = 66,
    IRQn_OTG_FS                 = 67,
    IRQn_DMA2_STREAM5           = 68,
    IRQn_DMA2_STREAM6           = 69,
    IRQn_DMA2_STREAM7           = 70,
    IRQn_USART6                 = 71,
    IRQn_I2C3_EV                = 72,
    IRQn_I2C3_ER                = 73,
    IRQn_OTG_HS_EP1_OUT         = 74,
    IRQn_OTG_HS_EP1_IN          = 75,
    IRQn_OTG_HS_WKUP            = 76,
    IRQn_OTG_HS                 = 77,
    IRQn_DCMI                   = 78,
    IRQn_CRYP                   = 79,
    IRQn_HASH_RNG               = 80,
    IRQn_FPU                    = 81,
    IRQn_default                = 999
}IRQn_t;

static inline uint32_t Is_valid_IRQn(IRQn_t irq) {return (irq < 82); }

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

/* EXTI base address definition*/
#define EXTI ((EXTI_RegDef_t*) EXTI_BASEADDR)

/* SYSCFG base address defnition */
#define SYSCFG ((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

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

/* enumeration of function state (EN/DIS) */
typedef enum {
    DISABLE = 0,
    ENABLE = 1
}State_t;

static inline uint32_t Is_valid_Function_State(State_t state) { return ( (state == ENABLE) || (state == DISABLE) ); }

/* periphral register definition structure for EXTI (external interrupt) */
typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
}EXTI_RegDef_t;

/* peripheral register definition structure for SYSCFG*/
typedef struct {
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4]; // EXTICR[0]: EXTI0-3, EXTICR[1]: EXTI4-7, EXTICR[2]: EXTI8-11, EXTICR[3]: EXTI12-15
    volatile uint32_t CMPCR;
    volatile uint32_t RESERVED[2]; // 0x20-0x24
    volatile uint32_t CFGR;
}SYSCFG_RegDef_t;

#endif