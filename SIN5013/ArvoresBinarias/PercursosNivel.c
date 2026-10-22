#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct no
{
    TIPOCHAVE chave;
    struct no *esq, *dir;
} NO;

typedef NO *PONT;

typedef struct elemento
{
    PONT item;
    struct elemento *prox;
} ELEMENTO;

typedef struct
{
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

bool entrarFila(FILA *f, PONT item)
{
    ELEMENTO *novo = malloc(sizeof(ELEMENTO));

    novo->item = item;
    novo->prox = NULL;

    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

bool sairFila(FILA *f, PONT *item)
{
    if (f->inicio == NULL)
        return false;

    ELEMENTO *apagar = f->inicio;
    *item = apagar->item;
    f->inicio = f->inicio->prox;

    free(apagar);

    if (f->inicio == NULL)
        f->fim = NULL;

    return true;
}

void exibirArvoreEmNivel(PONT raiz)
{
    FILA fila;
    PONT atual;

    inicializarFila(&fila);

    if (raiz == NULL)
        return;

    entrarFila(&fila, raiz);

    while (sairFila(&fila, &atual))
    {
        printf("%d ", atual->chave);

        if (atual->esq != NULL)
            entrarFila(&fila, atual->esq);

        if (atual->dir != NULL)
            entrarFila(&fila, atual->dir);
    }

    printf("\n");
}

int main(void)
{
    return 0;
}