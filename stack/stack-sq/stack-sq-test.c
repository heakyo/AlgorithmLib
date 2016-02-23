#include<stdio.h>
#include"stack-sq.h"

int main()
{
	stack_sq S;
	int a[] = {3, 8, 5, 17, 9, 30, 15, 22};
	int i;
	init_stack(&S, 5);
	for (i = 0; i < 8; i++)
	{
		push(&S, a[i]);
	}
	printf("%d ", pop(&S));
	printf("%d \n", pop(&S));
	
	push(&S, 68);
	printf("%d ", peek_stack(&S));
	printf("%d \n", pop(&S));
	
	while(!empty_stack(&S))
	{
		printf("%d ", pop(&S));
	}
	printf("\n");
	clear_stack(&S);

    return 0;
}
