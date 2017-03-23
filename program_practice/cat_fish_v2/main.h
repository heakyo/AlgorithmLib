/************************************************************************
*    File Name			:	template-main.h
*    Copyright			:	All Rights Reserved.
*    Module Name		:	Draw Engine/Display
*
*    CPU			:	x86
*    RTOS			:	Linux
*
*    Create Date		:	2016/xx/xx
*    Author/Corporation 	:	Marvin/xxxx
*
*    Abstract Description	:	Place some description here.
*
*-----------------------Revision History---------------------------------
*No	Version		Date		Revised By	Item		Description
*1	V0.1		xx.xx.16 	Marvin		xxxxxx		xxxxxx
*
************************************************************************/

/************************************************************************
*	Multi-Include-Prevent Section
************************************************************************/
#ifndef __FN_MAIN_H
#define __FN_MAIN_H

/************************************************************************
*	Debug switch Section
************************************************************************/

/************************************************************************
*	Include File Section
************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/************************************************************************
*	Macro Define Section
************************************************************************/
#define ARRAY_CNT(a) (sizeof(a) / sizeof(a[0]))

/************************************************************************
*	Struct Define Section
************************************************************************/
struct queue {
	int q[1000];
	int head, tail;
};

struct stack {
	int s[100];
	int top;
};

/************************************************************************
*	Extern Section
************************************************************************/

/************************************************************************
*	Prototype Declare Section
************************************************************************/


#endif


