#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO *PONT;

void exibirArvorePreOrdem(PONT raiz)
{
    if (raiz == NULL)
        return;
    printf("%i ", raiz->chave);
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}

void exibirArvoreEmOrdem(PONT raiz)
{
    if (raiz == NULL)
        return;
    exibirArvoreEmOrdem(raiz->esq);
    printf("%i ", raiz->chave);
    exibirArvoreEmOrdem(raiz->dir);
}

void exibirArvorePosOrdem(PONT raiz)
{
    if (raiz == NULL)
        return;
    exibirArvorePosOrdem(raiz->esq);
    exibirArvorePosOrdem(raiz->dir);
    printf("%i ", raiz->chave);
}