#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    Node *next;
} Node;

Node *insert_first(Node *head, int value)
{
    Node *p = malloc(sizeof(Node));
    p->data = value;
    p->next = head;
    head = p;
    return head;
}

Node *delete_first(Node *head)
{
    Node *deleteTarget = head;
    head = deleteTarget->next;
    free(deleteTarget);
    return head;
}

voi int main()
{
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
}