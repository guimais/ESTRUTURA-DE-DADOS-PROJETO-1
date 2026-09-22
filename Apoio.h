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
    aux->inicio = NULL;
    return aux;
}
int busca(Lista *L, int num)
{
    No *aux = L -> inicio;
    while(aux!=NULL){
        if(aux -> info == num ){
            return 1;
        }
        aux = aux -> prox;
    }
    return 0;
}

int LeCodigo (){
    int codigoQuatro;
    int flag = 0;
    while(codigoQuatro < 1000 || codigoQuatro > 9999){
        printf("Escreva um codigo de quatro digitos positivos: ");
        scanf("%d", &codigoQuatro);
        if(flag >= 1){
            printf("Numero invalido, coloque um decente. \n");
        }
        flag++;
    }
    return codigoQuatro;
}

void insereCodigo(Lista *L, int numeroSolicitacao)
{

    No *novo = (No*)malloc(sizeof(No));
    novo->info.CodigoDeSolicitacao = numeroSolicitacao;
    novo->prox = L->inicio;
    L->inicio = novo;
}




#endif
