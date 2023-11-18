#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int capacity;
    int top;
    int *array;
};

struct Stack *initStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
    {
        prtinf("Memory allocation failed. \n");
        return 1;
    }

    stack->capacity = capacity;
    stack->top = -1;

    stack->array = (int *)malloc(sizeof(int) * capacity);

    if (!stack->array)
    {
        prtinf("Memory allocation failed. \n");
        return 1;
    }

    return stack;
}

int main()
{
    int capacity = 5;

    struct Stack *stack1 = initStack(capacity);

    free(stack1);

    return 0;
}