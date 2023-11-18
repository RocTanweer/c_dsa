#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct ArrayQueue
{
    int array[MAX_SIZE];
    int front;
    int rear;
};

void initArrayQueue(struct ArrayQueue *arrayQueue)
{
    arrayQueue->front = arrayQueue->rear = -1;
}

int main(int argc, char const *argv[])
{
    struct ArrayQueue arrayQueue1;
    return 0;
}
