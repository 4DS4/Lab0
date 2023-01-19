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
	int location_1;
	char location_2;
	int location_3;
}ARBITRARY_MODULE;

#define MODULE ((ARBITRARY_MODULE*)0x20001000)

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

typedef struct
{
	char x1;
	short x2;
} test;

void testFunction2()
{
//	module := &struct_4{
//		inner_struct_1: inner_struct(x1:0xAA, x2:0xBBBB, x3:0xCCCCCCCC,),
//		x1: 0xDDDDDDDD,
//	}

	MODULE->location_1 = 0xAAAAAAAA;
	MODULE->location_2 = 0xBB;
	MODULE->location_3 = 0xCCCCCCCC;
	printf("%d", sizeof(struct_1));
	printf("%d", sizeof(struct_2));
	printf("%d", sizeof(struct_3));
	printf("%d", sizeof(struct_4));
	printf("%d", sizeof(test));
}


//
//int main(void)
//{
//    char ch;
//
//    /* Init board hardware. */
//    BOARD_InitBootPins();
//    BOARD_InitBootClocks();
//    BOARD_InitDebugConsole();
//
//    PRINTF("hello world.\r\n");
//    testFunction2();
//    while (1)
//    {
//        ch = GETCHAR();
//        PUTCHAR(ch);
//    }
//}
