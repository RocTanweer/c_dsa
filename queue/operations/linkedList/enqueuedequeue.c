#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (!newNode)
    {
        printf("Failed to allocate memory for Node\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

struct Queue *createQueue()
{
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));

    if (!newQueue)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void displayQueue(struct Queue *queue)
{
    struct Node *front = queue->front;

    while (front != NULL)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

void enqueue(struct Queue *queue, int element)
{
    struct Node *newNode = createNode(element);

    if (queue->front == NULL || queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue)
{
    if (queue->front == NULL || queue->rear == NULL)
    {
        printf("Cannot dequeue. Queue is empty\n");
        return -1;
    }
    else
    {
        struct Node *dequeuedNode = queue->front;
        int dequeuedElement = dequeuedNode->data;
        queue->front = queue->front->next;

        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }

        free(dequeuedNode);
        return dequeuedElement;
    }
}

int main()
{
    struct Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    displayQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    displayQueue(queue);

    return 0;
}