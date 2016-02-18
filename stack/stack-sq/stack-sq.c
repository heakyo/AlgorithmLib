#include"stack-sq.h"

void init_stack(stack_sq *S, int max_size)
{
    if (NULL == S)
    {
        printf("the pointer to stack is NULL.\n");
        exit(1);
    }    
 
    if (max_size <= 0)
    {
        printf("the stack can not be less zero.\n");
        exit(1);
    }

    S->stack = (ElemType *)malloc(sizeof(ElemType) * max_size);
    if (!S->stack)
    {
        free(S->stack);
        printf("init stack failed.\n");
        exit(1);
    }

    S->top = -1;
    S->max_size = max_size;
    
    return;
}

void clear_stack(stack_sq *S)
{
    if (NULL == S)
    {
        printf("the pointer to stack is NULL.\n");
        exit(1);
    }
    
    S->top = -1;
    S->max_size = 0;

    free(S->stack);
    S->stack = NULL;
   
    return;
}

int empty_stack(stack_sq *S)
{
    return ((S->top == -1) ? 1 : 0);
}

int full_stack(stack_sq *S)
{
    return ((S->top == (S->max_size - 1)) ? 1 : 0);
}

void push(stack_sq *S, ElemType x)
{
    if (full_stack(S))
    {
        realloc_stack(S);
    }

    S->top++;
    S->stack[S->top] = x;
    
    return;
}

ElemType pop(stack_sq *S)
{
    if (empty_stack(S))
    {
        printf("the stack is empty.\n");
        exit(1);
    }
    
    return S->stack[S->top--];
}

ElemType peek(stack_sq *S)
{
    if (empty_stack(S))
    {
        printf("the stack is empty.\n");
        exit(1);
    }
    
    return S->stack[S->top];
}


static void realloc_stack(stack_sq *S)
{
    ElemType *p = NULL;
    
    p = (ElemType *)realloc(S->stack, 2*S->max_size*sizeof(ElemType));
    if (!p)
    {
        printf("realloc stack failed.\n");
        exit(1);
    }

    S->stack = p;
    S->max_size = 2*S->max_size;

    return;
}

