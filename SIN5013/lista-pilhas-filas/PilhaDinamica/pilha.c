#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT topo;
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}

int tamanhoPilha(PILHA p)
{
    PONT atual = p.topo;
    int tam = 0;
    while (atual != NULL)
    {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false;

    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
    if (p->topo == NULL)
        return false;

    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

void exibirPilha(PILHA p)
{
    PONT atual = p.topo;
    printf("Pilha (Topo -> Base): ");
    while (atual != NULL)
    {
        printf("%d ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main()
{
    PILHA pilha;
    inicializarPilha(&pilha);

    REGISTRO reg1 = {10};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {30};

    inserirElemPilha(&pilha, reg1);
    inserirElemPilha(&pilha, reg2);
    inserirElemPilha(&pilha, reg3);

    exibirPilha(pilha);

    REGISTRO regExcluido;
    excluirElemPilha(&pilha, &regExcluido);
    printf("Elemento excluído: %d\n", regExcluido.chave);

    exibirPilha(pilha);

    return 0;
};