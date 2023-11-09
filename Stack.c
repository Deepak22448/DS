#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// helper function to create node.
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
// helper function determines if the stack is empty or not.
int isEmpty()
{
    return head == NULL;
}

// insert at the top of the stack.
void push(int data)
{

    struct Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    printf("%d pushed into the stack.\n", data);
}

// remove the top element from the stack.
int pop()
{
    if (isEmpty())
    {

        printf("Stack is Empty cannot pop. \n");
        return -1;
    }

    struct Node *new_head = head->next;
    int popedValue = head->data;
    free(head);
    head = new_head;

    printf("%d poped from the stack.\n", popedValue);
    return popedValue;
}

// print the elements in the stack.
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL \n");
}

int main(int argc, char const *argv[])
{
    push(3);
    push(2);
    display();
    pop();
    display();
    return 0;
}
