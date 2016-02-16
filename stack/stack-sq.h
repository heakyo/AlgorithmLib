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
//extern int a;

/************************************************************************
*	Macro Define Section
************************************************************************/
#define MAX_TIMER_OUT (4)

/************************************************************************
*	Struct Define Section
************************************************************************/
typedef struct CM_RadiationDose
{
    unsigned char ucCtgID;
    char cPatId_a[MAX_PATI_LEN];
}CM_RadiationDose_st, *CM_RadiationDose_pst;

/************************************************************************
*	Prototype Declare Section
************************************************************************/
unsigned int MD_guiGetScanTimes(void);


#endif


