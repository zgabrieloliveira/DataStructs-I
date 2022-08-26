#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// declaracao do no da *lista*
typedef struct node Node;
struct node {
    int info;
    Node *next;
};

// declaracao da lista em si
typedef struct lista Lista;
struct lista {
    Node *head;
//    Node *last;
};


Node *newNode(bool *deuCerto)
{
    Node *n;

    n = malloc(sizeof(Node));
    if (n == NULL) *deuCerto = false;
    else *deuCerto = true;

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Lista *criar(bool *deuCerto)
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L == NULL) *deuCerto = false;
    else {
        *deuCerto = true;
        L->head = NULL; // lista vazia
    }

    return L;
}

bool cheia(Lista *L)
{
    return false;
}

bool vazia(Lista *L)
{
    if (L->head == NULL) return true;
    else return false;
}

// Insere de maneira ordenada
void insereOrd(Lista *L, int X, bool *deuCerto)
{
    Node *p, *paux, *pant;
    bool ok;

    p = newNode(&ok); // nao vou tratar o erro se ok == false...
    p->info = X;

    // primeiro caso: lista vazia
    if (vazia(L) == true) {
        p->next = NULL;
        L->head = p;
    } else {
        // segundo caso: X serah o primeiro elemento
        paux = L->head;
        if (p->info < paux->info) {
            p->next = paux;
            L->head = p;
        } else {
            // terceiro caso: nao eh o primeiro
            // procura a posicao na lista
            while (p->info >= paux->info
                    && paux != NULL) {
                // avanca na lista
                pant = paux;
                paux = paux->next;
            }

            if (paux == NULL) {
                // (3.1) X serah o ultimo elemento
                p->next = NULL;
                pant->next = p;
            } else {
                // (3.2) X serah um node intermediario
                p->next = paux;
                pant->next = p;
            }
        }
        *deuCerto = true;
    }
    *deuCerto = false;
}

void retira(Lista *L, int X, bool *deuCerto)
{
    Node *p, *anterior;
    bool achou;

    p = L->head; // p = L
    anterior = NULL;

    // avanca na lista
    while ((p != NULL) && (p->info < X)) {
        anterior = p;
        p = p->next;
    }

    if ((p != NULL) && (p->info == X))
        achou = true;
    else achou = false;

    if (achou == true) {
        if (p != L->head) {
            anterior->next = p->next;
            deleteNode(p);
            p = NULL;
            anterior = NULL;
        } else {
            //L->head = L->head->next;
            L->head = p->next;
            deleteNode(p);
            p = NULL;
        } // fim if-else
        *deuCerto = true;
    } else *deuCerto = false;
}

void imprimeTodos(Lista *L)
{
    Node *p;

    p = L->head;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }

    printf("\n");
}


int pertence(Lista *l, int x, bool *deuCerto)
{
    if (l->head->info == x)
    {
        return 1;
    }
    else
    {
        l->head = l->head->next;
        pertence(l, x, deuCerto);
    }

    return 0;
}

int main()
{
    Lista *p;
    bool deuCerto;
    int valor;

    p = criar(&deuCerto);
    if (deuCerto == false) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }

    insereOrd(p, 1, &deuCerto);
    insereOrd(p, 2, &deuCerto);
    insereOrd(p, 3, &deuCerto);
    insereOrd(p, 4, &deuCerto);
    insereOrd(p, 5, &deuCerto);
    insereOrd(p, 6, &deuCerto);
    imprimeTodos(p);

    //valor = pertence(p, 1, &deuCerto);

    printf("%d", valor);

    return 0;
}