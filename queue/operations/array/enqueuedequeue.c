#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct ArrayQueue
{
    int array[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initArrayQueue(struct ArrayQueue *arrayQueue)
{
    arrayQueue->front = 0;
    arrayQueue->size = 0;
    arrayQueue->rear = MAX_SIZE - 1;
}

void enqueue(struct ArrayQueue *arrayQueue, int element)
{
    if (arrayQueue->size == MAX_SIZE)
    {
        printf("Queue is full. Cannot enqueue\n");
        return;
    }

    arrayQueue->rear = (arrayQueue->rear + 1) % MAX_SIZE;
    arrayQueue->array[arrayQueue->rear] = element;
    arrayQueue->size += 1;
    printf("Element %d is enqueued\n", element);
}

void dequeue(struct ArrayQueue *arrayQueue)
{
    if (arrayQueue->size == 0)
    {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }

    int dequeuedEl = arrayQueue->array[arrayQueue->front];

    arrayQueue->front = (arrayQueue->front + 1) % MAX_SIZE;
    arrayQueue->size -= 1;

    printf("Element %d is dequeued\n", dequeuedEl);
}

void printArrayQueue(struct ArrayQueue *arrayQueue)
{
    int i = 0;
    int arrQueueArrayI = arrayQueue->front;
    while (i < arrayQueue->size)
    {
        printf("%d ", arrayQueue->array[arrQueueArrayI]);

        arrQueueArrayI = (arrQueueArrayI + 1) % MAX_SIZE;

        i++;
    }
    printf("\n");
}

int main()
{
    struct ArrayQueue arrayQueue1;

    initArrayQueue(&arrayQueue1);

    enqueue(&arrayQueue1, 1);
    enqueue(&arrayQueue1, 3);
    enqueue(&arrayQueue1, 6);
    enqueue(&arrayQueue1, 8);

    printArrayQueue(&arrayQueue1);

    dequeue(&arrayQueue1);
    dequeue(&arrayQueue1);

    printArrayQueue(&arrayQueue1);

    return 0;
}