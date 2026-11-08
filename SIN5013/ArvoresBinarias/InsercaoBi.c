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

bool inserirNo2(PONT *raiz, TIPOCHAVE novaChave)
{
    if (*raiz == NULL)
    {
        *raiz = criarNovoNo(novaChave);
        return true;
    }
    else
        return inserirAux(*raiz, novaChave);
}

bool inserirAux(PONT raiz,
                TIPOCHAVE ch)
{
    if (raiz->chave >= ch)
    {
        if (raiz->esq == NULL)
        {
            raiz->esq = criarNovoNo(ch);
            return true;
        }
        else
            return inserirAux(raiz->esq, ch);
    }
    else
    {
        if (raiz->dir == NULL)
        {
            raiz->dir = criarNovoNo(ch);
            return true;
        }
        else
            return inserirAux(raiz->dir, ch);
    }
}

PONT criarNovoNo(TIPOCHAVE ch)
{
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo;
}