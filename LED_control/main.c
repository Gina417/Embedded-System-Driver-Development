#include <stdint.h>
#include "stm32f407.h"
#include "rcc.h"
#include "gpio.h"

volatile int LED_mode = 0;

typedef enum {
    green = 0,
    orange = 1,
    red = 2,
    blue = 3,
    all = 4     
}LED_On_Mode_t;

/* Initialize all the LED */
void LED_Init(void)
{
    /* Enable GPIOD clock */
    GPIOD_ClkCtrl(ENABLE);

    /* Initialize GPIO of Green LED */
    GPIO_Handle_t green_led_handle;
    green_led_handle.pGPIOx = GPIOD;
    green_led_handle.pin = GPIO_PIN_12;
    green_led_handle.mode = MODER_OUTPUT;
    green_led_handle.otype = OTYPER_PP;
    green_led_handle.ospeed = OSPEEDR_LOW;
    green_led_handle.pupd = PUPDR_NONE;

    /* Initialize GPIO of Orange LED */
    GPIO_Handle_t orange_led_handle;
    orange_led_handle.pGPIOx = GPIOD;
    orange_led_handle.pin = GPIO_PIN_13;
    orange_led_handle.mode = MODER_OUTPUT;
    orange_led_handle.otype = OTYPER_PP;
    orange_led_handle.ospeed = OSPEEDR_LOW;
    orange_led_handle.pupd = PUPDR_NONE;

    /* Initialize GPIO of Red LED */
    GPIO_Handle_t red_led_handle;
    red_led_handle.pGPIOx = GPIOD;
    red_led_handle.pin = GPIO_PIN_14;
    red_led_handle.mode = MODER_OUTPUT;
    red_led_handle.otype = OTYPER_PP;   
    red_led_handle.ospeed = OSPEEDR_LOW;
    red_led_handle.pupd = PUPDR_NONE;

    /* Initialize GPIO of Blue LED */
    GPIO_Handle_t blue_led_handle;
    blue_led_handle.pGPIOx = GPIOD;
    blue_led_handle.pin = GPIO_PIN_15;
    blue_led_handle.mode = MODER_OUTPUT;
    blue_led_handle.otype = OTYPER_PP;
    blue_led_handle.ospeed = OSPEEDR_LOW;
    blue_led_handle.pupd = PUPDR_NONE;

    GPIO_Init(&green_led_handle);
    GPIO_Init(&orange_led_handle);
    GPIO_Init(&red_led_handle);
    GPIO_Init(&blue_led_handle);
}

/* Implement different LED toggle case */
void LED_toggle(LED_On_Mode_t mode)
{
    switch (mode) {
        case green:
            // Turn on the green LED
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            // Delay
            for (uint32_t i = 0; i < 300000; i++);
            // Turn  off the green LED
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            break;

        case orange:
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            break;

        case red:
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            break;

        case blue:
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for (uint32_t i = 0; i < 300000; i++);
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);

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
            break;

        default:
            break;
    }
    LED_mode = (LED_mode + 1) % 5; // Cycle through the LED modes
}

int main(void)
{
    /* Initialize the LEDs */
    LED_Init();

    /* Toggle the LEDs */
    while(1){
        LED_toggle(LED_mode);
    }
}