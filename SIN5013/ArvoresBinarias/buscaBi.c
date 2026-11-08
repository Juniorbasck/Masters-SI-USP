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

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz)
{
    if (raiz == NULL)
        return NULL;
    if (raiz->chave == ch)
        return raiz;
    if (raiz->chave < ch)
        return buscaBinaria(ch, raiz->dir);
    return buscaBinaria(ch, raiz->esq);
}

PONT buscaBinariaIterativa(PONT raiz, TIPOCHAVE ch)
{
    PONT atual = raiz;
    while (atual)
    {
        if (atual->chave == ch)
            return atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return NULL;
}