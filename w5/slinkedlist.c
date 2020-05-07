// slinkedlist.c
// Implementation of a linked list
// only for integers
// Somaditya Sinha
// 8 April 2020

#include <stdio.h>
#include <stdlib.h> //malloc()

typedef struct node
{
    int n;
    struct node *nexp;
} node;


// Function prototypes
node *createll(int val);
void add(node **head, int val);
node *searchll(node *head, int val);
void begone(node **head);

//_________MAIN FUNCTION___________
int main(void)
{
    node *head = createll(5);

    add(&head, 3);
    add(&head, 420);
    add(&head, 69);

    printf("%i\n", searchll(head, 3)->n);

    begone(&head);
    return 0;
}

// Function definitions
// Create the head of a linked list
node *createll(int val)
{
    node *tmp = malloc(sizeof(node));
    tmp->n = val;
    tmp->nexp = NULL;
    return tmp;
}

// Add a value at the end of a linked list
void add(node **head, int val)
{
    node *tmp = malloc(sizeof(node));

    tmp->n = val;
    tmp->nexp = *head;
    *head = tmp;
}

// Search for a value in a linked list
node *searchll(node *head, int val)
{
    node* trav = head;
    while (trav != NULL)
    {
        if (trav->n == val)
            return trav;
        else
            trav = trav->nexp;
    }
    return NULL;

}

// Destroy your precious little list
void begone(node **head)
{
    node *trav = *head;
    do
    {
        node *tmp = trav;
        trav = trav->nexp;
        free(tmp);
    }
    while(trav != NULL);
}