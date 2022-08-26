/* 

  TRABALHO PRÁTICO ED1 - RECURSÃO

Gabriel Antônio de Oliveira Leite, 12111BSI222
Augusto Fernandes Macri, 12111BSI221
Arthur Ferreira da Silva, 12111BSI259

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// REGISTROS:

typedef struct node Node;

struct node 
{
  int info;
  Node *next;
};

typedef struct list List;

struct list
{
  Node *head;
};


// FUNÇÕES TAD: 

Node *createNode(bool *ok);
void deleteNode(Node *n);
List *createList(bool *ok);
bool listFull(List *L);
bool listEmpty(List *L);
void insertSorted(List *L, int x, bool *ok);
void removeElement(List *L, int x, bool *ok);

// FUNÇÕES RECURSIVAS: 

void pertenceRecursivo(Node *node, int elem, int *ok);
int pertence(List *l, int elem);
int ultimoRecursivo(Node *node, int *ok);
int ultimo(List *l);
int somaRecursiva(Node *node, int *s);
int soma(List *l);
int somaImparesRecursiva(Node *node, int *s);
int somaImpares(List *l);
int n_esimoRecursivo(Node *node, int n, int *ok);
int n_esimo(List *l, int n);
int comprimentoRecursivo(Node *node, int contador);
int comprimento(List *l);


Node *createNode(bool *ok)
{

  Node *n;
  n = (Node *) malloc(sizeof(Node));

  if (n == NULL)
    *ok = false;
  else
    *ok = true;

  return n;

}

void deleteNode(Node *n)
{
  if (n != NULL)
    free(n);
}

List *createList(bool *ok)
{

  List *L;
  L = (List *) malloc(sizeof(List));

  if (L == NULL)
    *ok = false;
  else
  {
    *ok = true;
    L->head = NULL;
  }

  return L;

}

bool listFull(List *L)
{ 
  return false; 
}

bool listEmpty(List *L)
{

  if (L->head == NULL)
    return true;
  else
    return false;

}

void insertSorted(List *L, int x, bool *ok)
{

  Node *p, *paux, *pant;
  bool  ok1;

  // Criação de nó que contém o elemento a ser inserido
  p = createNode(&ok1);
  p->info = x;

  // Lista vazia, a cabeça da lista aponta para NULL
  if (listEmpty(L) == true) 
  {
    p->next = NULL;
    L->head = p;
  }
  else 
  {
    // Lista com apenas um elemento, verifica ordenação para inserção
    paux = L->head;

    if (p->info < paux->info) 
    {
      p->next = paux;
      L->head = p;
    } 
    else 
    {
      
      // Lista com mais de um elemento, é necessário percorrê-la
      while (p->info >= paux->info && paux != NULL)
      {
        pant = paux;
        paux = paux->next;
      }

      // inserção na última posição da lista
      if (paux == NULL) 
      {
        p->next = NULL;
        pant->next = p;
      }
      // inserção no meio da lista
      else 
      {
        p->next = paux;
        pant->next = p;
      }
    }
  }

  *ok = true;

}

void removeElement(List *L, int x, bool *ok)
{

  Node *p, *ant;
  bool foundElement;

  p = L->head;
  ant = NULL;

  // percorrendo lista enquanto houver elementos menores que o elemento a ser removido
  while ((p != NULL) && (p->info < x))
  {
    ant = p;
    p = p->next;
  }

  if ((p != NULL) && (p->info == x))
    foundElement = true;

  else
    foundElement = false;

  /*  após encontrar elemento, o removemos 
      apontando o seu antecessor para seu sucessor
      e deletando o nó do elemento removido */
  if (foundElement == true) 
  {
    
    if (p != L->head) 
    {
      ant->next = p->next;
      deleteNode(p);
      p = NULL;
      ant = NULL;
    }

    /*  se o elemento for a cabeça da lista, 
        a cabeça passa a apontar para o seu sucessor 
        e o nó do elemento removido é deletado */
    else 
    {
      // L->head = L->head->next;
      L->head = p->next;
      deleteNode(p);
      p = NULL;
    }

    *ok = true;
  
  }

  // se o elemento não estiver na lista, a operação não foi pode ser realizada
  else
    *ok = false;

}

void pertenceRecursivo(Node *node, int elem, int *ok)
{

  // caso a lista estiver vazia, não há elementos pertencentes
  if (node == NULL)
    *ok = 0;

  else 
  { 
    // caso o elemento seja a cabeça da lista, ele pertence à lista
    if (node->info == elem)
      *ok = 1;

    // caso não pertence a cabeça, chamada recursiva com o próximo elemento da lista
    else
      pertenceRecursivo(node->next, elem, ok);
  }

}

int pertence(List *l, int elem)
{

  Node *node;
  int ok;

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  pertenceRecursivo(node, elem, &ok); // chamada da função recursiva
  return ok;

}

int ultimoRecursivo(Node *node, int *ok)
{

  // se a lista estiver vazia, não há último elemento
  if (node == NULL)
  {
    *ok = 0;
    return;
  }

  else
  {
    // se o nó de um elemento apontar para NULL, esse elemento é o último da lista
    if (node->next == NULL)
    {
      *ok = 1;
      return node->info;
    } 

    // caso o nó do elemento não apontar para NULL, a lista é percorrida recursivamente
    else
      ultimoRecursivo(node->next, ok);
  }

}

int ultimo(List *l)
{

  Node *node;
  int ok, u;

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  u = ultimoRecursivo(node, &ok); // chamada da função recursiva
  return u;

}

int somaRecursiva(Node *node, int *s)
{

  // caso a lista estiver vazia a variável contendo a soma de elementos é retornada
  if (node == NULL)
    return *s;

  // se houver elemento na lista, esse elemento é somado e a operação se repete recursivamente
  if (node->next != NULL)
  {
    *s = *s + (node->info);
    somaRecursiva(node->next, s);
  } 

  else 
  {
    *s = *s + (node->info);
    return *s;
  }

}

int soma(List *l)
{

  Node *node;
  int s;

  s = 0; // soma inicializada em 0

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  somaRecursiva(node, &s); // chamada da função recursiva
  return s;

}

int somaImparesRecursiva(Node *node, int *s)
{

  // caso a lista estiver vazia a variável contendo a soma de elementos é retornada
  if (node == NULL)
    return *s;

  // se houver elemento na lista e ele for ímpar, esse elemento é somado e a operação se repete recursivamente
  if ((node->next != NULL))
  {
    if (((node->info % 2 != 0)))
    {
      *s = *s + (node->info);
      somaImparesRecursiva(node->next, s);
    } 

    else
      somaImparesRecursiva(node->next, s);
  }

  else if (node->info % 2 != 0)
  {
    *s = *s + (node->info);
    return *s;
  }

}

int somaImpares(List *l)
{

  Node *node;
  int s;

  s = 0; // soma inicializada em 0

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  somaImparesRecursiva(node, &s); // chamada da função recursiva
  return s;

}

int n_esimoRecursivo(Node *node, int n, int *ok)
{
  
  // caso a lista estiver vazia, não há n-esimo elemento
  if (node == NULL)
    *ok = 0;

  // caso haja elemento(s) na lista, se n não for igual a 0, n-esimo elemento é procurado recursivamente
  else
  {
    *ok = 1;

    if (n == 0)
        return node->info;
    else
      return n_esimoRecursivo(node->next, n-1, ok);
  }
  
}

int n_esimo(List *l, int n)
{
  
  Node *node;
  int ok;

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  return n_esimoRecursivo(node, n, &ok); // retorna resultado da função recursiva
  
}

int comprimentoRecursivo(Node *node, int contador)
{
  
  // se a lista estiver vazia, variável contendo o comprimento da lista é retornada
  if (node == NULL)
    return contador; 
  
  // a cada elemento da lista, comprimento é incrementado em 1 e a operação se repete recursivamente
  else 
  {
    contador++; 
    return comprimentoRecursivo(node->next, contador);
  }
    
}

int comprimento(List *l)
{
  
  Node *node;
  int contador;

  contador=0; // comprimento inicializado em 0

  node = l->head; // nó passa a apontar para onde a cabeça aponta

  return comprimentoRecursivo(node, contador); // retorna resultado da função recursiva
  
}

int main(void)
{

  List *l;
  bool deuCerto;
  int x, n, elemento;

  l = createList(&deuCerto); // criação da lista utilizada

  if (deuCerto == false)
  {
    printf("ERRO AO CRIAR A LISTA!!\n");
    exit(1);
  }

  // leitura dos números verificados pelas funções pertence e n-esimo, respectivamente
  scanf("%d %d", &x, &n); 

  // preenchimento da lista, ordenadamente
  while (scanf("%d", &elemento) != EOF)
  {
    insertSorted(l, elemento, &deuCerto);
  }

  // resultado das funções recursivas

  printf("%d\n", pertence(l, x));
  printf("%d\n", n_esimo(l, n));

  printf("%d\n", ultimo(l));
  printf("%d\n", soma(l));
  printf("%d\n", somaImpares(l));
  printf("%d\n", comprimento(l));

  return 0;

}