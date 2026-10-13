#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int chave;
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

int tamanho(LISTA *l)
{
    PONT end = l->inicio;
    int tam = 0;

    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }

    return tam;
}

int main()
{
    LISTA l;
    inicializarLista(&l);
    printf("Tamanho da lista: %d\n", tamanho(&l));

    PONT no1 = (PONT)malloc(sizeof(ELEMENTO));
    no1->chave = 10;
    no1->prox = NULL;
    l.inicio = no1;
    printf("Tamanho da lista: %d\n", tamanho(&l));

    PONT no2 = (PONT)malloc(sizeof(ELEMENTO));
    no2->chave = 20;
    no2->prox = NULL;
    no1->prox = no2;
    printf("Tamanho da lista: %d\n", tamanho(&l));

    return 0;
}