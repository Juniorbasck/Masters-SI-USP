#include <stdio.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
} FILA;

bool inserirElementoFila(FILA *f, REGISTRO reg)
{
    if (f->nroElem >= MAX)
        return false;

    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao] = reg;
    f->nroElem++;

    return true;
}
bool excluirElementoFila(FILA *f, REGISTRO *reg)
{
    if (f->nroElem == 0)
        return false;

    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;

    return true;
}

void inicializarFila(FILA *f)
{
    f->inicio = 0;
    f->nroElem = 0;
}

int main()
{
    FILA fila;
    inicializarFila(&fila);

    REGISTRO reg1 = {1};
    REGISTRO reg2 = {2};
    REGISTRO reg3 = {3};

    inserirElementoFila(&fila, reg1);
    inserirElementoFila(&fila, reg2);
    inserirElementoFila(&fila, reg3);

    return 0;
}