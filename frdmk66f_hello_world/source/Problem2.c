/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */

typedef struct
{
	char x2;
	int x1;
} struct_1;
typedef struct
{
	short x2;
	int x1;
} struct_2;
typedef struct
{
	int x1;
	short x2;
} struct_3;
typedef struct
{
	struct inner_struct
	{
		char x1;
		short x2;
		int x3;
	} inner_struct_1;
	int x1;
} struct_4;

#define MODULE1 ((struct_1*)0x20001010)
#define MODULE2 ((struct_2*)0x20001020)
#define MODULE3 ((struct_3*)0x20001030)
#define MODULE ((struct_4*)0x20001000)

void testFunction2()
{
	MODULE->inner_struct_1.x1 = 0x11;
	MODULE->inner_struct_1.x2 = 0x2222;
	MODULE->inner_struct_1.x3 = 0x33333333;
	MODULE->x1 = 0x44444444;

	MODULE1->x2 = 0x11;
	MODULE1->x1 = 0x22222222;

	MODULE2->x2 = 0x1111;
	MODULE2->x1 = 0x22222222;

	MODULE3->x1 = 0x11111111;
	MODULE3->x2 = 0x2222;

	printf("struct 1 %d", sizeof(struct_1));
	printf("struct 2 %d", sizeof(struct_2));
	printf("struct 3 %d", sizeof(struct_3));
	printf("struct 4 %d", sizeof(MODULE));
}



int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("hello world.\r\n");
    testFunction2();
    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
}
