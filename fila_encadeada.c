#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DEFINIÇÃO DE REGISTROS:

typedef struct
{
    char info;
    Node *next;
}
Node;

typedef struct
{

}
Queue;


// FUNÇÕES:

Node *createNode (bool *works);             // cria nós
void deleteNode (Node *n);                  // libera memória alocada p/ os nós
Queue *createQueue (bool *works);           // cria fila
bool queueFull (Queue *q);                  // verifica se a fila está cheia
bool queueEmpty (Queue *q);                 // verifica se a fila está vazia
void push (Queue *q, char x, bool *works);  // 
void pop (Queue *q, char *x, bool *works);  // 
void destroyQueue (Queue *q);               // libera memória alocada p/ fila 


Node *createNode (bool *works)
{

    Node *n;

    n = (Node *) malloc(sizeof(Node));

    if (n != NULL)
        *works = true;
    else 
        *works = false;

}

void deleteNode (Node *n)
{
    if (n != NULL)
        free(n);
}

Queue *createQueue (Queue *q)
{
    
    Queue *q; 

    q = (Queue *) malloc(sizeof(Queue));

    if (q != NULL)
    {
        *works = 1;
        //
    }

    else 
        *works = 0;

    return q;

}

bool queueFull (Queue *q)
{
    return false;
}




