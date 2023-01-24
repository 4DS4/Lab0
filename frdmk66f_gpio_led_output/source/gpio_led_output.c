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
#include "registers.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIOD     GPIO_D
#define BOARD_LED_GPIOC     GPIO_C
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
    /* Board pin, clock, debug console init */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n The LED is blinking.\r\n");

    /* Init output LED GPIO. */
    GPIO_Init(BOARD_LED_GPIOC, BLUE_PIN);
    GPIO_Init(BOARD_LED_GPIOC, GREEN_PIN);
    GPIO_Init(BOARD_LED_GPIOD, RED_PIN);

    while (1)
    {

        GPIO_Toggle(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        delay();
        GPIO_Toggle(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        GPIO_Toggle(BOARD_LED_GPIOC, 1u << GREEN_PIN);
        delay();
        GPIO_Toggle(BOARD_LED_GPIOC, 1u << GREEN_PIN);
    	GPIO_Toggle(BOARD_LED_GPIOD, 1u << RED_PIN);
		delay();
		GPIO_Toggle(BOARD_LED_GPIOD, 1u << RED_PIN);
		delay();
        GPIO_On(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        GPIO_On(BOARD_LED_GPIOD, 1u << RED_PIN);
        delay();
        GPIO_Off(BOARD_LED_GPIOC, 1u << BLUE_PIN);
        GPIO_Off(BOARD_LED_GPIOD, 1u << RED_PIN);

    }
}
