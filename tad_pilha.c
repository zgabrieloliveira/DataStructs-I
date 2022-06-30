#include <stdlib.h>
#include <stdio.h>

/*  1 = true
    0 = false   */

#define MAX 10

// Pilha estática e sequencial
typedef struct
{

    int topo;
    char elementos[MAX];

}
Pilha;


// Funções
Pilha *criar (int *funciona);
void destruir (Pilha *p);
int vazia (Pilha *p);
int cheia (Pilha *p);
int empilhar (Pilha *p, char x, int *funciona);
char desempilhar (Pilha *p, char *x, int *funciona);


Pilha *criar (int *funciona)
{

    Pilha *p;
    
    p = (Pilha *) malloc(sizeof(Pilha));
    
    // memória não foi alocada
    if (p == NULL)
        *funciona = 0;

    // memória alocada, pilha inicia em 0 
    else
    {
        p-> topo = -1;
        *funciona = 1;
    }

    return p;

}


void destruir (Pilha *p)
{

    if (p != NULL)
        free(p); 
    
}


int vazia (Pilha *p)
{

    // A pilha está vazia
    if(p->topo == -1)
        return 1; 

    else
        return 0;

}


int cheia (Pilha *p)
{

    // pilha está cheia 
    if(p->topo == MAX-1) // contagem começa em 0, logo a posição máxima decresce em 1
        return 1; 
        
    else
        return 0; 

}


int empilhar (Pilha *p, char x, int *funciona)
{

    // a pilha está cheia
    if(cheia(p) == 1)
        *funciona = 0;
    
    else
    {
        (p->topo)++; // incrementando pilha
        p->elementos[p->topo] = x; // empilhando no topo
        *funciona = 1;
    }

}


char desempilhar (Pilha *p, char *x, int *funciona)
{
     
    // a pilha está vazia
    if(vazia(p) == 1)
        *funciona = 0;
       

    else
    {  
        *x = p->elementos[p->topo]; // desempilhando elemento no topo
        (p->topo)--; // decrementando pilha
        *funciona = 1;
    }
    
}


int main (void)
{

    Pilha *p;
    int funciona;
    char x;
    
    p = criar(&funciona);
    
    if (funciona == 0)
    {
        printf("NÃO FOI POSSÍVEL CRIAR A PILHA!\n\n");
        exit(1);
    }
    
    empilhar (p, 'a', &funciona);
    empilhar (p, 'b', &funciona);
    empilhar (p, 'c', &funciona);
    empilhar (p, 'd', &funciona);
    empilhar (p, 'e', &funciona);
    empilhar (p, 'f', &funciona);
    empilhar (p, 'g', &funciona);
    empilhar (p, 'h', &funciona);
    empilhar (p, 'i', &funciona);
    empilhar (p, 'j', &funciona);
    desempilhar (p, &x, &funciona);
    empilhar (p, 'k', &funciona);
    
    if (cheia(p) == 1) 
        printf("A PILHA ESTÁ CHEIA, NÃO É POSSÍVEL EMPILHAR\n\n");
    
    desempilhar (p, &x, &funciona);
    printf("   %c\n", x);

    destruir (p);

    return 0;

}