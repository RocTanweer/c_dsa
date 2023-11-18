#include <stdio.h>
#include <stdlib.h>

struct ArrayStack
{
    int *array;
    int capacity;
    int top;
};

struct ArrayStack *initArrayStack(int capacity)
{
    struct ArrayStack *arrayStack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));

    if (!arrayStack)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    arrayStack->array = (int *)malloc(sizeof(int) * capacity);

    if (!arrayStack->array)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    arrayStack->capacity = capacity;
    arrayStack->top = -1;

    return arrayStack;
}

void printArrayStack(struct ArrayStack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void pushArrayStack(struct ArrayStack *arrayStack, int element)
{
    if (arrayStack->top == arrayStack->capacity - 1)
    {
        printf("Stack is full. Cannot push %d\n", element);
        return;
    }

    arrayStack->array[++arrayStack->top] = element;
    printf("Pushed element %d onto the stack\n", element);
}

int popArrayStack(struct ArrayStack *arrayStack)
{
    if (arrayStack->top == -1)
    {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    else
    {
        int poppedData = arrayStack->array[arrayStack->top--];
        printf("Popped element %d from the stack\n");
        return poppedData;
    }
}

int main(int argc, char const *argv[])
{
    int capacity = 5;

    struct ArrayStack *stack1 = initArrayStack(capacity);

    for (int i = 0; i < capacity; i++)
    {
        printf("Enter element %d: ", i + 1);
        int input;

        scanf("%d", &input);

        pushArrayStack(stack1, input);
    }

    printArrayStack(stack1);

    int pop1 = popArrayStack(stack1);

    printArrayStack(stack1);

    free(stack1->array);
    free(stack1);

    return 0;
}
