/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "registers.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIOD     GPIOD
#define BOARD_LED_GPIOC     GPIOC
#define BLUE_PIN 8
#define RED_PIN 1
#define GREEN_PIN 9

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    /* Board pin, clock, debug console init */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n The LED is blinking.\r\n");

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_LED_GPIOC, BLUE_PIN, &led_config);
    GPIO_PinInit(BOARD_LED_GPIOC, GREEN_PIN, &led_config);
    GPIO_PinInit(BOARD_LED_GPIOD, RED_PIN, &led_config);

    while (1)
    {

        GPIO_PortToggle(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        delay();
        GPIO_PortToggle(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        GPIO_PortToggle(BOARD_LED_GPIOC, 1u << GREEN_PIN);
        delay();
        GPIO_PortToggle(BOARD_LED_GPIOC, 1u << GREEN_PIN);
        GPIO_PortToggle(BOARD_LED_GPIOD, 1u << RED_PIN);
        delay();
        GPIO_PortToggle(BOARD_LED_GPIOD, 1u << RED_PIN);
    }
}
