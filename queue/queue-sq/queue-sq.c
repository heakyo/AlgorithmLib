#include"queue-sq.h"

void init_queue(queue_sq *Q, int max_size)
{
    if (NULL == Q)
    {
        printf("the pointer to queue is NULL.\n");
        exit(1);
    }    
 
    if (max_size <= 0)
    {
        printf("the queue can not be less zero.\n");
        exit(1);
    }

    Q->queue = (ElemType *)malloc(sizeof(ElemType) * max_size);
    if (!Q->queue)
    {
        free(Q->queue);
        printf("init queue failed.\n");
        exit(1);
    }

    Q->front = Q->rear = 0;
    Q->max_size = max_size;
    
    return;
}

void clear_queue(queue_sq *Q)
{
    if (NULL == Q)
    {
        printf("the pointer to queue is NULL.\n");
        exit(1);
    }
    
    Q->front = Q->rear = 0;
    Q->max_size = 0;

    free(Q->queue);
    Q->queue = NULL;
   
    return;
}

int empty_queue(queue_sq *Q)
{
	return ((Q->front == Q->rear) ? 1 : 0);
}

int full_queue(queue_sq *Q)
{
	return (((Q->rear+1)%Q->max_size == Q->front) ? 1 : 0);
}

void in_queue(queue_sq *Q, ElemType x)
{

    if (full_queue(Q))
    {
        realloc_queue(Q);
    }

    Q->rear = ((Q->rear + 1) % Q->max_size);
    Q->queue[Q->rear] = x;
    
    return;
}

ElemType out_queue(queue_sq *Q)
{

    if (empty_queue(Q))
    {
        printf("the queue is empty.\n");
        exit(1);
    }

	Q->front = ((Q->front + 1) % Q->max_size);
    
    return Q->queue[Q->front];
}

ElemType peek_queue(queue_sq *Q)
{
	int front = 0;

    if (empty_queue(Q))
    {
        printf("the queue is empty.\n");
        exit(1);
    }

	front = ((Q->front + 1) % Q->max_size);
    
    return Q->queue[front];
}


static void realloc_queue(queue_sq *Q)
{
    ElemType *p = NULL;
    
    p = (ElemType *)realloc(Q->queue, 2*Q->max_size*sizeof(ElemType));
    if (!p)
    {
        printf("realloc queue failed.\n");
        exit(1);
    }

    Q->queue = p;
    Q->max_size = 2*Q->max_size;

    return;
}

