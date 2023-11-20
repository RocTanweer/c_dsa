#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printStack(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *push(struct Node *head, int element)
{
    struct Node *newNode = createNode(element);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *pop(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return head;
    }

    struct Node *poppedNode = head;
    head = head->next;
    free(poppedNode);
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 6);
    head = push(head, 7);
    head = push(head, 8);
    head = push(head, 9);
    head = push(head, 10);
    head = push(head, 11);
    head = push(head, 12);
    head = push(head, 13);
    head = push(head, 14);
    head = push(head, 15);
    head = push(head, 16);
    head = push(head, 17);
    head = push(head, 18);

    printStack(head);

    head = pop(head);
    head = pop(head);
    head = pop(head);

    printStack(head);

    return 0;
}
