#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// helper method to create node.
struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// delete last element from list.
void push(int data)
{
    struct Node *new_node = create_node(data);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
}

// delete last element from list.
void pop()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// delete first element from list.
void shift()
{
    if (head == NULL)
        return;

    struct Node *new_head = head->next;
    free(head);
    head = new_head;
}

// insert at first position of list;
void un_shift(int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
}

// insert element at a specified position in list.
void insertAt(int data, int position)
{
    if (position < 0)
    {
        printf("Invalid position to `insertAt` position can not be negative.\n");
        return;
    }

    if (position == 0)
    {
        return un_shift(data);
    }

    struct Node *new_node = create_node(data);
    struct Node *current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition != position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL)
    {
        printf("Invalid position `position` exeeds the length of list.\n");
        return;
    }

    if (current->next == NULL)
        return;

    new_node->next = current->next;
    current->next = new_node;
}

// delete element at a specified position in list.
void deleteAt(int position)
{
    if (position < 0 || head == NULL)
    {
        return;
    }

    if (position == 0)
    {
        return shift();
    }

    struct Node *current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition != position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// display all the elements of the list.
void display()
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    push(4);
    push(5);
    push(9);
    insertAt(99, 1);
    deleteAt(2);
    display();

    return 0;
}
