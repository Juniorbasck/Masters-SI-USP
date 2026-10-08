#include <stdio.h>

#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}

int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch; 
    
    while (l->A[i].chave != ch) {
        i++;
    }
    
    if (i == l->nroElem) 
        return -1;
    else 
        return i; 
}

int main() {
    LISTA lista;
    inicializarLista(&lista);

    lista.A[0].chave = 10;
    lista.A[1].chave = 25;
    lista.A[2].chave = 42;
    lista.nroElem = 3;

    TIPOCHAVE buscado = 25;
    int pos = buscaSentinela(&lista, buscado);

    if (pos != -1) {
        printf("Chave %d encontrada no indice %d\n", buscado, pos);
    } else {
        printf("Chave %d nao encontrada\n", buscado);
    }

    return 0;
}