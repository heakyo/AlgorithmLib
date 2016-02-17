/*****************************************************************************************
*    File Name			:	stack-sq.h
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
*----------------------------------------Revision History---------------------------------
*No	Version		Date		Revised By	Item		Description
*1	V0.1		xx.xx.16 	Marvin		xxxxxx		xxxxxx
*
************************************************************************/

/************************************************************************
*	Multi-Include-Prevent Section
************************************************************************/
#ifndef __STACK_SQ_H 
#define __STACK_SQ_H

/************************************************************************
*	Debug switch Section
************************************************************************/
#define D_STACK_SQ

/************************************************************************
*	Include File Section
************************************************************************/
#include <stdio.h>

/************************************************************************
*	Extern Section
************************************************************************/

/************************************************************************
*	Macro Define Section
************************************************************************/

/************************************************************************
*	Struct Define Section
************************************************************************/
typedef char ElemType;

typedef sturct _stack_sq {
    ElemType *stack;
    int top;
    int max_size;
} stack_sq;


/************************************************************************
*	Prototype Declare Section
************************************************************************/
int init_stack(stack_sq *S, int max_size);
int clear_stack(stack_sq *S);

void push(stack_sq *S, ElemType x);
ElemType pop(stack_sq *S);

int empty_stack(stack_sq *S);
int full_stack(stack_sq *S);

int peek(stack_sq *S);

#endif


