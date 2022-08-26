// Arthur Ferreira da Silva, 12111BSI259
// Gabriel Antonio de Oliveira Leite, 12111BSI222
// Augusto Fernandes Macri, 12111BSI221

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int elements[50];
};

typedef struct stack Stack; // tipo pilha

Stack *create(int *deuCerto, int tamanhoDaPilha)
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));

    if (stack == NULL)
    {
        *deuCerto = 0; // nao foi possivel criar a pilha
    }
    else
    {
        *deuCerto = 1; // pilha criada com sucesso
        stack->top -= 1;
    }

    return stack;
}

// função para verificar o estado vazio da pilha, comparando o topo com a menor posição possivel
int isEmpty(Stack *stack)
{

    int firstStackPosition = -1;
    return (stack->top == firstStackPosition);
}

// função para verificar o estado cheio da pilha, comparando o topo com a quantidade máxima de entidades suportada pela pilha
int isFull(Stack *stack)
{

    return (stack->top == 50);
}

// função para inserir um item no topo da pilha
int push(Stack *stack, int element) // incrementar elemento na pilha
{

    if (isFull(stack))
    {

        return 0;
    }
    else
    {
        stack->top += 1;
        stack->elements[stack->top] = element;
    }
    return 1;
}

// função que retira o item do topo da pilha
int pop(Stack *stack) // remover elemento da pilha
{

    int poppedElement;

    if (isEmpty(stack))
    {

        return 0;
    }
    else
    {

        poppedElement = stack->elements[stack->top];
        stack->top -= 1;
    }
    return poppedElement;
}

// função para pegar qual numero está no topo da pilha, sem retira-lo
void stack_top(Stack *stack, int *line)
{
    *line = stack->elements[stack->top];
    return;
}

// função que libera o espaço alocado dinamicamente para a pilha
void destroy(Stack *stack) // liberar espaco alocado anteriormente para a pilha
{

    if (stack != NULL) // se a pilha existir
    {
        free(stack);
    }
}

// função para alocar dinamicamente a matriz de valores
int **criaMatriz(int tamanhoDaMatriz, int *deuCerto)
{
    int **matriz;
    int i;
    tamanhoDaMatriz++;

    matriz = (int **) calloc(tamanhoDaMatriz, sizeof(int *));
    for (i = 0; i < tamanhoDaMatriz; i++)
        matriz[i] = (int *) calloc(tamanhoDaMatriz, sizeof(int));
    
    *deuCerto = 1;
    
    if(matriz == NULL)
    {
    	*deuCerto = 0;
    }
    
    return matriz;
}

// função para preenher a matriz com valores nulos (função calloc) onde não há conexão entre pontos ou preencher com o custo onde há conexão
void preencheMatriz(int **matriz, int qtdConexoes)
{
    int ponto1, ponto2, peso;
    int i;

    for (i = 0; i < qtdConexoes; i++)
    {
        setbuf(stdin, NULL);
        scanf("%d %d %d", &ponto1, &ponto2, &peso);
        matriz[ponto1 - 1][ponto2 - 1] = peso;
    }

    return;
}

void destroyMatriz(int **matriz, int tamanhoDaMatriz)
{
	int i;
	for (i = 0; i < tamanhoDaMatriz; i++)
        	free(matriz[i]);

    free(matriz);
}

int main(void)
{
    
    int deuCerto;
    int vertices; // tamanho da matriz
    int arestas;  // quantidade de pontos conectados
    int **matriz;
    int inicio, fim;
    int custo = 0;
    int columnAux, lineAux;
    int column, line;

    Stack *lineStack;
    Stack *columnStack;

    setbuf(stdin, NULL);
    scanf("%d %d", &vertices, &arestas);

    lineStack = create(&deuCerto, arestas); // criação da pilha de linhas

    // verificando se a pilha de linhas foi criada e alocada com sucesso
    if (deuCerto == 0)
    {
        exit(1); // o programa não funciona sem a pilha, então se ela nao for criada o programa deve encerrar
    }

    columnStack = create(&deuCerto, arestas); // crição da pilha de colunas

    // verificando se a pilha de colunas foi criada e alocada com sucesso
    if (deuCerto == 0)
    {
        exit(1);
    }

    // chamada da função para alocação e preenchimento da matriz dinamica
    matriz = criaMatriz(vertices, &deuCerto);
    
    if (deuCerto == 0)
    {
        exit(1);
    }

    // preenchimento da matriz com os pontos que tem conexão
    preencheMatriz(matriz, arestas);

    // leitura dos pontos do caminho que deseja encontrar
    setbuf(stdin, NULL);
    scanf("%d %d", &inicio, &fim);
    
    line = inicio - 1;

    while (1)
    {
        // column menor ou igual, caso o valor esteja na ultima posição,
        // quando desempilhado rode mais 1 vez para dar outro rollback.
        for (column = 0; column <= vertices; column++)
        {
	
            if (column == fim - 1 && matriz[line][column] != 0)
            {
                custo += matriz[line][column];
                break;
            }
            
            if (matriz[line][column] != 0)
            {
                custo += matriz[line][column];
                push(columnStack, column);
                push(lineStack, line);
                stack_top(columnStack, &line);
                // se ficar zero ele entrar de volta no looping com valor igual a 1 ( linha 127)
                column = -1;
            }
            
            if (column == fim - 1 && matriz[line][column] != 0)
            {
                break;
            }
		
            // verifica se chegou na ultima prosição da matriz
            if (column >= vertices - 1)
            {

                if (isEmpty(lineStack))
                {
                    custo = -1;
                    break;
                }
                
                // pega quais foram as ultimas posições de linha e coluna para subtrair o custo anterior e retira os valores da pilha
                stack_top(lineStack, &lineAux);
                stack_top(columnStack, &columnAux);
		
                custo -= matriz[lineAux][columnAux];
                
                column = pop(columnStack);
                line = pop(lineStack);

            }
        }
        
        break;
    }
	    
    // printa o custo final caso haja caminho
    printf("%d\n", custo);

    // libera o espaço alocado para as pilhas
    destroy(columnStack);
    destroy(lineStack);
    
    // liberação da matriz dinamica
    destroyMatriz(matriz, vertices);
    
                    

    return 0;
}
