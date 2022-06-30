#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    
    float x;
    float y;
    
}
Ponto; 

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
    free (p);
}

float acessar_x (Ponto *p)
{
    return p->x;
}

float acessar_y (Ponto *p)
{
    return p->y;
}

Ponto *atribuir (float x1, float y1)
{
    
    Ponto *p;
    
    if (p != NULL)
    {
        p->x = x1;
        p->y = y1;
    }
    
   return p;
    
}

int main(void)
{
    
    Ponto *p;
    float x, y;
    
    printf("Digite as coordenadas x e y: ");
    scanf("%f %f", &x, &y);

    p = criar (x, y);
    
    if (p == NULL)
        printf("ERRO: Coordenadas Inválidas\n\n");
    
    else
    {
        printf("O valor do eixo x eh: %.2f\n", acessar_x(p));
        printf("O valor do eixo y eh: %.2f\n", acessar_y(p));
    }
    
    printf("Digite as novas coordenadas x e y: ");
    scanf("%f %f", &x, &y);
    
    p = atribuir (x, y);
    
    if (p == NULL)
        printf("ERRO: Coordenadas Inválidas\n\n");
    
    else
    {
        printf("O valor do eixo x eh: %.2f\n", acessar_x(p));
        printf("O valor do eixo y eh: %.2f\n", acessar_y(p));
    }
    
    printf("A distancia entre os pontos x e y eh: ");
    
    destruir(p);
    
    return 0;
    
}