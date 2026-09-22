#include <stdio.h>
#include <stdlib.h>
#include "Apoio.h"

int main()
{
    lista *L = CriaLista
    int Opcao;

    printf("**************************************************************");
    printf("\n Gerenciador de Manutencao de Equipamentos de um Laboratorio");

    printf("\n\n\tDigite 1 - NOVA SOLICITACAO");
    printf("\n\tDigite 2 - REMOVER SOLICITACAO");
    printf("\n\tDigite 3 - CONSULTAR SOLICITACAO");
    printf("\n\tDigite 4 - ALTERAR PRIORIDADE E/OU PERIODO DE SOLICITACAO");
    printf("\n\tDigite 5 - ORDEM DA REALIZACAO DA MANUTENCAO");
    printf("\n\tDigite 6 - TODAS SOLICITACOES");
    printf("\n\tDigite 0 - SAIR");

    printf("\n\n**************************************************************");

    do{
        scanf("%d", &Opcao);

        switch(Opcao){
            case 1:
                printf("Ola");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;
            default:
                printf("Seu numero e invalido. Digite novamente");
                break;
        }
    }
    while (Opcao <0  || Opcao > 7);


    return 0;
}

