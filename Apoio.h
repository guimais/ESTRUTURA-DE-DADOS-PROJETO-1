#ifndef APOIO_H_INCLUDED
#define APOIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  CodigoDeSolicitacao;
    char CodigoEquipamentos[7];
    char nome[20];
    int  prioridade;
    int  periodo;
} Solicitacao;

typedef struct no {
    Solicitacao info;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
} Lista;

Lista* CriaLista()
{
    Lista *aux;
    aux=(Lista *)malloc(sizeof(Lista));
    aux->inicio=NULL
    return aux;
}

#endif
