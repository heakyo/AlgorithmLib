/*****************************************************************************************
*    File Name			:	btree-node.h
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
#ifndef __BTREE_NODE_H 
#define __BTREE_NODE_H

/************************************************************************
*	Debug switch Section
************************************************************************/
#define D_BTREE_NODE

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

typedef struct _btree_node {
	ElemType data;
	struct _btree_node *left_node;
	struct _btree_node *right_node;
} btree_node;


/************************************************************************
*	Prototype Declare Section
************************************************************************/
void init_btree(btree_node **bt);
void create_btree(btree_node **bt, char *a);
void clear_btree(btree_node **bt);

int empty_btree(btree_node *bt);
int depth_btree(btree_node *bt);
ElemType *find_btree(btree_node *bt, ElemType x);
void print_btree(btree_node *bt);

#endif


