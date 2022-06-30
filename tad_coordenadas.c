#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    
    float x;
    float y;
    
}
Ponto; 


// Funções

Ponto *criar (float x1, float y1);
void destruir (Ponto *p);
Ponto atribuir (Ponto *p, float x1, float y1);
void acessar (Ponto *p, float *x, float *y);
float distancia (Ponto *a, Ponto *b);


Ponto *criar (float x1, float y1)
{
   
   Ponto *p;
   
    p = (Ponto *) malloc(sizeof(Ponto));
    
    if (p != NULL)
    {
        p->x = x1;
        p->y = y1;
    }
    
   return p;
    
}


void destruir (Ponto *p)
{

    if (p != NULL)
        free (p);

}


Ponto atribuir (Ponto *p, float x1, float y1)
{

    // atribuindo novos valores de coordenadas para os eixos X e Y
    p->x = x1;
    p->y = y1;

}


void acessar (Ponto *p, float *x, float *y)
{

    // acessando campo da coordenada de cada eixo
    *x = p->x;
    *y = p->y;

}


float distancia (Ponto *a, Ponto *b)
{
    
    float d; 

    /*   CÁLCULO DA DISTÂNCIA ENTRE DOIS PONTOS:

        - calcular a diferença entre os respectivos eixos dos dois pontos;
        - elevar o resultado do cálculo de cada ponto ao quadrado;
        - calcular a raíz da soma desses quadrados.   */
    
    d = (float) sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y , 2));
    
    return d;

}


int main (void)
{
    
    Ponto *a;
    Ponto *b;
    float x, y;

    a = criar(3.0, 5.0);
    b = criar(6.0, 1.0);

    acessar(a, &x, &y);
    printf("\nAs coordenadas (x,y) de A são: (%.2f, %.2f)", x, y);

    acessar(b, &x, &y);
    printf("\nAs coordenadas (x,y) de B são: (%.2f, %.2f)\n", x, y);

    printf("\nA distancia entre A e B é: %.2f\n", distancia(a, b));

    atribuir(a, 5.0, 5.0);
    acessar(a, &x, &y);
    printf("\nAs NOVAS coordenadas (x,y) de A são: (%.2f, %.2f)", x, y);

    atribuir(b, 3.0, 7.0);
    acessar(b, &x, &y);
    printf("\nAs NOVAS coordenadas (x,y) de B são: (%.2f, %.2f)\n", x, y);

    printf("\nA distancia entre A e B é: %.2f\n\n", distancia(a, b));

    destruir(a);
    destruir(b);

    return 0;
    
}