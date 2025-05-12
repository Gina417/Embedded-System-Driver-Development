#include <stdint.h>
#include "module.h"

typedef enum {
    green = 0,
    orange = 1,
    red = 2,
    blue = 3,
    all = 4     
}LED_On_Mode_t;

volatile int LED_mode = 0;

/* Initialize all the LED */
void LED_Init(void)
{

    /* Initialize GPIO of Green LED */
    GPIO_Handle_t green_led_handle = {
        .pGPIOx = GPIOD,
        .pin = GPIO_PIN_12,
        .mode = MODER_OUTPUT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_LOW,
        .pupd = PUPDR_NONE
    };
    GPIO_Init(&green_led_handle);

    /* Initialize GPIO of Orange LED */
    GPIO_Handle_t orange_led_handle = {
        .pGPIOx = GPIOD,
        .pin = GPIO_PIN_13,
        .mode = MODER_OUTPUT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_LOW,
        .pupd = PUPDR_NONE
    };
    GPIO_Init(&orange_led_handle);

    /* Initialize GPIO of Red LED */
    GPIO_Handle_t red_led_handle = {
        .pGPIOx = GPIOD,
        .pin = GPIO_PIN_14,
        .mode = MODER_OUTPUT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_LOW,
        .pupd = PUPDR_NONE
    };
    GPIO_Init(&red_led_handle);

    /* Initialize GPIO of Blue LED */
    GPIO_Handle_t blue_led_handle = {
        .pGPIOx = GPIOD,
        .pin = GPIO_PIN_15,
        .mode = MODER_OUTPUT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_LOW,
        .pupd = PUPDR_NONE
    };
    GPIO_Init(&blue_led_handle);
}

void LED_toggle(LED_On_Mode_t mode)
{
    switch (mode) {
        case green:
            // Turn on the green LED
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            for (uint32_t i = 0; i < 300000; i++);
            // Turn  off the green LED
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            for (uint32_t i = 0; i < 300000; i++);
            break;

        case orange:
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            for (uint32_t i = 0; i < 300000; i++);
            break;

        case red:
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            for (uint32_t i = 0; i < 300000; i++);
            break;

        case blue:
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for (uint32_t i = 0; i < 300000; i++);
            break;

        case all:
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for (uint32_t i = 0; i < 300000; i++);
            break;

        default:
            break;
    }
}

void Btn_Init(void)
{
    /* Initialize button */
    GPIO_Handle_t button_handle = {
        .pGPIOx = GPIOA,
        .pin = GPIO_PIN_0,
        .mode = MODER_EXTI_FT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_LOW,
        .pupd = PUPDR_NONE
    };
    GPIO_Init(&button_handle);

    NVIC_Handle_t button_IRQ_handle = {
        .IRQ_number = IRQn_EXTI0,
        .Gpriority = 1,
        .Spriority = 1
    };

    NVIC_PrioityGroupConfig(GP4_SP0);
    NVIC_SetPriority(&button_IRQ_handle);
    NVIC_IRQ_Enable(&button_IRQ_handle);
}

void LED_ON_PIN(void){
    LED_mode = (LED_mode + 1) % 5;
}

int main(void)
{
    /* Enable GPIOA clock */
    GPIOA_ClkCtrl(ENABLE);

    /* Enable GPIOD clock */
    GPIOD_ClkCtrl(ENABLE);

    /* Initialize the LEDs */
    LED_Init();
    Btn_Init();

    EXTI0_IRQ_Callback(LED_ON_PIN);

    /* Toggle the LEDs */
    while(1){
        LED_toggle(LED_mode);
    }
}