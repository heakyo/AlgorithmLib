#include"stack-sq.h"

int init_stack(stack_sq *S, int max_size)
{
    if (NULL == S)
    {
        perror("the pointer to stack is NULL");
        return -1;
    }    
 
    if (max_size <= 0)
    {
        perror("the stack can not be less zero");
        return -1;
    }

    S->stack = (ElemType *)malloc(sizeof(ElemType) * max_size);
    if (!S->stack)
    {
        free(S->stack);
        perror("init stack failed");
        return -1;
    }

    S->top = -1;
    S->max_size = max_size;
    
    return 0;
}

int clear_stack(stack_sq *S)
{
    if (NULL == S)
    {
        perror("the pointer to stack is NULL");
        return -1;
    }
    
    S->top = -1;
    S->max_size = 0;

    free(S->stack);
    S->stack = NULL;
   
    return 0;
}

int main() {

    
    return 0;
}

