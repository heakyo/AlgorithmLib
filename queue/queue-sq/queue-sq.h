/*****************************************************************************************
*    File Name			:	queue-sq.h
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
#ifndef __QUEUE_SQ_H 
#define __QUEUE_SQ_H

/************************************************************************
*	Debug switch Section
************************************************************************/
#define D_QUEUE_SQ

/************************************************************************
*	Include File Section
************************************************************************/
#include<stdio.h>
#include<stdlib.h>

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

typedef struct _queue_sq {
    ElemType *queue;
    int front, rear, len;
    int max_size;
} queue_sq;


/************************************************************************
*	Prototype Declare Section
************************************************************************/
void init_queue(queue_sq *Q, int max_size);
void clear_queue(queue_sq *Q);

void in_queue(queue_sq *Q, ElemType x);
ElemType out_queue(queue_sq *Q);

int empty_queue(queue_sq *Q);
int full_queue(queue_sq *Q);

ElemType peek_queue(queue_sq *Q);

static void realloc_queue(queue_sq *Q);

#endif


