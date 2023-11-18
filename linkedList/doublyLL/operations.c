#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// function to insert at the beginning
struct Node *insertAtBeginning(struct Node *head, int element)
{
    struct Node *newNode = createNode(element);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

// function to delete at the beginning
struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return head;
    }

    struct Node *deletedNode = head;
    head = deletedNode->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(deletedNode);
    return head;
}

struct Node *insertAtEnd(struct Node *head, int element)
{
    struct Node *newNode = createNode(element);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, cannot deleted\n");
        return head;
    }

    if (head->next == NULL && head->prev == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    struct Node *deletedNode = temp;
    deletedNode->prev->next = NULL;
    free(deletedNode);
    return head;
}

// function to insert at nth position
struct Node *inserAtNthPos(struct Node *head, int element, int pos)
{
    struct Node *newNode = createNode(element);

    if (pos == 1 || head == NULL)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
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
        printf("Out of range, Cannot insert %d at position %d\n", element, pos);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// function to delete at nth postion
struct Node *deleteAtNthPos(struct Node *head, int pos)
{
    struct Node *deletedNode;
    if (pos == 1 && head == NULL)
    {
        printf("List is empty, invalid deletion.\n");
        return head;
    }

    if (pos == 1 && head != NULL)
    {
        deletedNode = head;
        head = deletedNode->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(deletedNode);
        return head;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid delete position.\n");
        return head;
    }

    deletedNode = temp;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(deletedNode);
    return head;
}

void printDLL(struct Node *head)
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

    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);

    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);

    head = inserAtNthPos(head, 4, 4);
    head = inserAtNthPos(head, 5, 5);
    head = inserAtNthPos(head, 6, 6);

    head = deleteAtBeginning(head);

    head = deleteAtEnd(head);

    head = deleteAtNthPos(head, 3);

    head = deleteAtNthPos(head, 1);
    head = deleteAtNthPos(head, 6);

    printDLL(head);

    return 0;
}