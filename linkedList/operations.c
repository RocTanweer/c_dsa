#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function to create a node with a given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert at the beginning
struct Node *insertAtBeginning(struct Node *head, int element)
{
    struct Node *newNode = createNode(element);

    newNode->next = head;
    head = newNode;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int element)
{
    struct Node *newNode = createNode(element);

    if (head == NULL)
    {
        head = newNode;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

struct Node *insertAtNthPos(struct Node *head, int element, int pos)
{
    struct Node *newNode = createNode(element);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of rangen\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printLinkedList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 6);
    head = insertAtBeginning(head, 8);
    head = insertAtBeginning(head, 1);

    head = insertAtEnd(head, 9);

    head = insertAtNthPos(head, 5, 1);
    head = insertAtNthPos(head, 4, 1);
    head = insertAtNthPos(head, 10, 6);

    printLinkedList(head);

    return 0;
}