#include<stdio.h>
#include<stdlib.h>
#include"queue-sq.h"

int main()
{
	queue_sq Q;
	int a[] = {3,8,5,17,9,30,15,22};	
	int i = 0;
	init_queue(&Q, 5);
	for (i = 0; i < 8; i++)
	{
		in_queue(&Q, a[i]);
	}
	printf("%d ", out_queue(&Q));
	printf("%d \n", out_queue(&Q));
	in_queue(&Q, 68);
	printf("%d ", peek_queue(&Q));	
	printf("%d \n", out_queue(&Q));
	while (!empty_queue(&Q)) 
	{
		printf("%d ", out_queue(&Q));
	}
	printf("\n");
	clear_queue(&Q);	

	return 0;
}
