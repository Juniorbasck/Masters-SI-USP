#include <stdio.h>
#include <stdlib.h>

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
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
    PONT pos = l->inicio;
    while (pos != NULL)
    {
        if (pos->reg.chave == ch)
            return pos;
        pos = pos->prox;
    }
    return NULL;
}

PONT buscaSeqOrd(LISTA *l, TIPOCHAVE ch)
{
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch)
    {
        pos = pos->prox;
    }
    if (pos != NULL && pos->reg.chave == ch)
        return pos;

    return NULL;
}

int main()
{
    LISTA l;
    inicializarLista(&l);

    PONT no1 = (PONT)malloc(sizeof(ELEMENTO));
    no1->reg.chave = 10;
    no1->prox = NULL;
    l.inicio = no1;

    PONT no2 = (PONT)malloc(sizeof(ELEMENTO));
    no2->reg.chave = 20;
    no2->prox = NULL;
    no1->prox = no2;

    PONT no3 = (PONT)malloc(sizeof(ELEMENTO));
    no3->reg.chave = 30;
    no3->prox = NULL;
    no2->prox = no3;

    PONT no4 = (PONT)malloc(sizeof(ELEMENTO));
    no4->reg.chave = 40;
    no4->prox = NULL;
    no3->prox = no4;

    PONT no5 = (PONT)malloc(sizeof(ELEMENTO));
    no5->reg.chave = 50;
    no5->prox = NULL;
    no4->prox = no5;

    PONT resultado = buscaSequencial(&l, 30);
    printf("Elemento encontrado: %d\n", resultado->reg.chave);

    return 0;
}