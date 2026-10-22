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

int altura(PONT p)
{
    if (!p)
        return -1;
    else
        return 1 + max(altura(p->esq), altura(p->dir));
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int numeroNos(PONT raiz)
{
    if (!raiz)
        return 0;
    return 1 + numeroNos(raiz->esq) + numeroNos(raiz->dir);
}