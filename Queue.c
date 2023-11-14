#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

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

// function insert into the queue.
void enque(int data)
{
    struct Node *new_node = create_node(data);

    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }

    printf("[ENQUE] : %d added to the queue.\n", data);
}

// function to remove from the queue.
int deque()
{
    if (head == NULL)
    {
        printf("Empty Queue.\n");
        return -1;
    }

    int removedValue = head->data;
    struct Node *new_head = head->next;

    free(head);
    head = new_head;

    if (head == NULL)
        tail = NULL;

    printf("[DEQUE] : %d removed from queue.\n", removedValue);

    return removedValue;
}

// helper function to print the queue items.
void display()
{
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
    enque(3);
    enque(2);
    display();
    deque();
    display();
    return 0;
}
