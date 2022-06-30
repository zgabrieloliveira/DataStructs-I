#include <stdio.h>
#include <stdlib.h>

/*  1 = true
    0 = false   */

#define MAX 5

// Fila circular estática e sequencial
typedef struct
{

    int inicio;
    int final;
    int n_elementos;
    char elementos[MAX];

}
Fila;

// Funções
Fila *criar (int *funciona);
void destruir (Fila *f);
int cheia (Fila *f);
int vazia (Fila *f);
void inserir (Fila *f, char x, int *funciona);
void remover (Fila *f, char *x, int *funciona);


Fila *criar (int *funciona)
{

    Fila *f;

    f = malloc (sizeof(Fila));

    // memória não foi alocada
    if (f == NULL)
        *funciona = 0;
    
    // memória alocada, fila se inicia em 0
    else 
    {
        f->inicio = 0;
        f->final = 0;
        f->n_elementos = 0;
        *funciona = 1;
    }

    return f;

}

void destruir (Fila *f)
{
    
    if (f != NULL)
        free(f);

}


int vazia (Fila *f)
{

    // fila vazia 
    if (f->n_elementos == 0)
        return 1;

    else 
        return 0;

}


int cheia (Fila *f)
{

    // fila cheia 
    if (f->n_elementos == MAX)
        return 1;

    else 
        return 0;

}


void inserir (Fila *f, char x, int *funciona)
{

    // fila cheia, não é possível inserir 
    if (cheia(f) == 1)
        *funciona = 0;

    else 
    {
        *funciona = 1;
        (f->n_elementos)++;
        f->elementos[f->final] = x; // inserção na última posição

        // rotacionando fila, o fim se torna o começo
        if (f->final == (MAX-1))
            f->final = 0;

        else
            (f->final)++;
    }

}


void remover (Fila *f, char *x, int *funciona)
{

    // fila está vazia
    if (vazia(f) == 1)
        *funciona = 0;

    else
    {
        *funciona = 1;
        (f->n_elementos)--;
        *x = f->elementos[f->inicio]; // remoção na primeira posição

        // rotacionando fila, o fim se torna o começo
        if (f->final == (MAX-1))
            f->final = 0;

        else 
            (f->final)++;
    }

}


int main (void)
{

    Fila *f;
    int funciona;

    f = criar(&funciona);

    if (funciona  == 0)
    {
        printf("ERRO: Não foi possível criar a fila\n");
        exit(-1);
    }

    inserir (f, 'a', &funciona);

    if (funciona == 1)
        printf("TAD FILA IMPLEMENTADO COM SUCESSO!\n");

    else 
        printf("TAD FILA NÃO PÔDE SER IMPLEMENTADO!\n");

    return 0;

}