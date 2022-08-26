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
    Node *top;
}
Stack;


// FUNÇÕES:

Node *createNode (bool *works);             // cria nós
void deleteNode (Node *n);                  // libera memória alocada p/ os nós
Stack *createStack (bool *works);           // cria pilha
bool stackFull (Stack *s);                  // verifica se a pilha está cheia
bool stackEmpty (Stack *s);                 // verifica se a pilha está vazia
void push (Stack *s, char x, bool *works);  // empilha elementos na pilha
void pop (Stack *s, char *x, bool *works);  // desempilha elementos na pilha 
void destroyStack (Stack *s);               // libera memória alocada p/ pilha 


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

Stack *createStack (bool *works)
{

    Stack *s; 

    s = (Stack *) malloc(sizeof(Stack));

    if (s != NULL)
    {
        *works = 1;
        s->top = NULL;
    }

    else 
        *works = 0;

    return s;

}

bool stackFull (Stack *s)
{
    return false;   // estruturas encadeadas não tem limitante além da memória
}

bool stackEmpty (Stack *s)
{

    if (s->top == NULL)
        return true;

    else 
        return false;

}

void push (Stack *s, char x, bool *works)
{

    Node *node_aux;
    bool ok;

    // a pilha está cheia
    if (full(s) == true)
        *works = false;

    else 
    {
        node_aux = createNode(&ok); // criação de nó auxiliar
        node_aux->info = x;         // nó auxiliar recebe o dado
        node_aux->next = s->top;    // o nó para o próximo elemento aponta para o topo da pilha
        s->top = node_aux;          // o topo aponta para o nó auxiliar
        *works = true;              // operação funcionou
    }
 
}

void pop (Stack *s, char *x, bool *works)
{

    Node *node_aux;

    // a pilha está vazia
    if (stackEmpty(s) == true)
        *works = false;

    else
    {
        node_aux = s->top;          // nó auxiliar aponta para o topo da pilha
        *x = node_aux->info;        // o dado no topo passa p/ nó auxiliar
        s->top = node_aux->next;    // o topo agora é o elemento anterior ao topo
        deleteNode(node_aux);       // deleta nó auxiliar
        *works = true;              // operação funcionou 
    }

}

void destroyStack (Stack *s)
{

    bool works;
    char x;

    // enquanto a pilha não estiver vazia, elementos serão desempilhados
    while (stackEmpty(s) == false)
        pop(s, &x, &works);

    // liberação de memória alocada p/ pilha
    free(s);

}


int main (void)
{

    Stack *s;
    bool works;
    char x;
    
    s = createStack (&works);

    if (works == false)
    {
        printf("ERRO: Não foi possível criar a pilha!\n");
        exit(1);    // Se a pilha não é criada, o programa para
    }
    
    push (s, 'A', &works);
    push (s, 'B', &works);
    push (s, 'C', &works);
    
    destroyStack(s);

    return 0;

}