#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack-sq.h"
#include"queue-sq.h"

static int is_win(stack_sq *S, int *pos)
{
	int i = 0;

	for (i = 0; i < S->top; i++)
	{
		if (S->stack[i] == peek_stack(S))
		{
			*pos = i;

			return 1;
		}
	}	

	return 0;
}

static void get_card(queue_sq *Q, stack_sq *S, int pos)
{
	while(S->top >= pos)
	{
		in_queue(Q, pop(S));
	}	

	return;
}

int main() 
{
	queue_sq Aq, Bq;
	stack_sq card_pool_stk;
	int card_count = 20;
	//const ElemType A[] = {2,4,1,2,5,6};
	//const ElemType B[] = {3,1,3,5,6,4};
	const ElemType A[] = {1,2,3};
	const ElemType B[] = {3,2,1};
	ElemType card = 0;
	int i = 0;
	int pos = 0;

	init_queue(&Aq, card_count);
	init_queue(&Bq, card_count);
	init_stack(&card_pool_stk, card_count);
	
	//memcpy(Aq.queue, A, sizeof(A));
	//memcpy(Bq.queue, B, sizeof(B));
	
	printf("A's inital cards: ");
	for (i = 0; i < sizeof(A); i++)
	{
		in_queue(&Aq, A[i]);
		printf("%d ", A[i]);
	}
	printf("\n");

	printf("B's inital cards: ");
	for (i = 0; i < sizeof(B); i++)
	{
		in_queue(&Bq, B[i]);
		printf("%d ", B[i]);
	}
	printf("\n");

	/* start game */
	while (!empty_queue(&Aq) && !empty_queue(&Bq))
	{
		card = out_queue(&Aq);
		push(&card_pool_stk, card); // A plays a card
		//printf("A:%d ", card);
		
		if (is_win(&card_pool_stk, &pos))
		{
			printf("A gets cards.\n");
			get_card(&Aq, &card_pool_stk, pos);	
		}
		 	
		card = out_queue(&Bq);
		push(&card_pool_stk, card); // B plays a card
		//printf("B:%d ", card);
		
		if (is_win(&card_pool_stk, &pos))
		{
			printf("B gets cards.\n");
			get_card(&Bq, &card_pool_stk, pos);	
		}
	
	}

	if(empty_queue(&Bq))
	{
		/* A win */
		printf("A win!! A's cards: ");
		while(!empty_queue(&Aq))
		{
			printf("%d ", out_queue(&Aq));
		}
		printf("\n");
	} else if(empty_queue(&Aq))
	{
		/* B win */
		printf("B win!! B's cards: ");
		while(!empty_queue(&Bq))
		{
			printf("%d ", out_queue(&Bq));
		}
		printf("\n");
	}

	/* show the desk cards */
	printf("Desk cards: ");
	while(!empty_stack(&card_pool_stk))
	{
		printf("%d ", pop(&card_pool_stk));
	}
	printf("\n");
	

    return 0;
}

