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
        if(aux -> info.CodigoDeSolicitacao == num ){
            return 1;
        }
        aux = aux -> prox;
    }
    return 0;
}

int LeCodigo(Lista *L) {
    int codigoQuatro = 0;
    while (codigoQuatro < 1000 || codigoQuatro > 9999 || busca(L, codigoQuatro) == 1) {
        printf("Escreva um codigo de quatro digitos: ");
        scanf("%d", &codigoQuatro);
        if (codigoQuatro < 1000 || codigoQuatro > 9999) {
            printf("Numero invalido, coloque um decente.\n");
        }
        else if (busca(L, codigoQuatro) == 1) {
            printf("Este codigo ja esta em uso\n");
        }
    }
    return codigoQuatro;
}


void insereCodigo(Lista *L, Solicitacao novaSolicitacao) {
    No *novo = (No*)malloc(sizeof(No));

    
    novo->info = novaSolicitacao;
    novo->prox = NULL;

  
    if (L->inicio == NULL || L->inicio->info.CodigoDeSolicitacao >= novaSolicitacao.CodigoDeSolicitacao) {
        novo->prox = L->inicio;
        L->inicio = novo;
        return;
    }
   
    No *atual = L->inicio;
    
    while (atual->prox != NULL && atual->prox->info.CodigoDeSolicitacao < novaSolicitacao.CodigoDeSolicitacao) {
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
}
void imprimir(Lista *L) {
    No *aux= L->inicio;
    while (aux!=NULL) {
        printf("Codigo :%d\n",aux->info.CodigoDeSolicitacao);
        printf("Equipamento:%s\n",aux->info.CodigoEquipamentos);
        printf("Nome:%s\n",aux->info.nome);
        printf("Prioridade:%d\n",aux->info.prioridade);
        printf("Periodo (dias):%d\n",aux->info.periodo);
        aux=aux->prox;
    }
}

Solicitacao preencher(int codigoQuatro){
    Solicitacao atual;
    atual.CodigoDeSolicitacao = codigoQuatro;
    while (getchar() != '\n');
    printf("qual o nome do equipamento?");
    fgets(atual.nome, 20, stdin);

    printf("Codigo do Equipamento (Ex: OSC023): ");
    fgets(atual.CodigoEquipamentos, 7, stdin);
    atual.prioridade=0;
    while (atual.prioridade <1 || atual.prioridade>3) {
            printf("qual a prioridade?");
            scanf("%d",&atual.prioridade);
        if (atual.prioridade<1 || atual.prioridade>3) {
            printf("digite uma prioridade de 1 a 3");
        }
    }
    int flag =0;
    while (flag==0) {
        printf("Qual o perido?");
        scanf("%d",&atual.periodo);
        if (atual.prioridade==1 && atual.periodo>=1 && atual.periodo<=7) {
            flag=1;
        }else if (atual.prioridade == 2 && atual.periodo >= 1 && atual.periodo <= 15) {
            flag = 1;
        } else if (atual.prioridade == 3 && atual.periodo >= 1 && atual.periodo <= 20) {
            flag = 1;
        } else {
            printf("Periodo invalido para a prioridade %d. Tente novamente.\n", atual.prioridade);
        }
    }
    return atual;
    }



#endif
