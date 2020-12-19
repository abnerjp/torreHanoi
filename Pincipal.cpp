// ABNER J�COMO PELISSER
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
// CONSTANTES
#define MAXPILHA 30
#define QTDE_PILHA 3


#include "Funcoes.h"
#include "Manual.h"
#include "Automatico.h"

int MENU (int &escolha) {
    do {
        printf("---------------------------------TORRE DE HANOI---------------------------------");
        printf("\n\t1 - Automatico\n\t2 - Manual\n\t3 - Sair\n-> ");
        scanf("%d",&escolha);
    } while(escolha < 1 || escolha > 3);
    return escolha;
}

void DADOS_INICIO(TpPilha &p, int &qtde_discos, int &origem, int &destino, int &aux) { // FUNCAO PARA INFORMA�OS E COLETA DE DADOS PAR AO JOGO
    do { // INFORMA QUANTOS DISCOS SERAO UTILIZADOS
        printf("Deseja jogar com quantos discos?(max %d): ",MAXPILHA / QTDE_PILHA);
        scanf("%d", &qtde_discos);
    } while(qtde_discos <= 0 || qtde_discos > MAXPILHA/QTDE_PILHA);

    do { // SELECIONA A HASTE ORIGEM
        printf("Informe a haste de ORIGEM(1=A,2=B ou 3=C): ");
        scanf("%d", &origem);
    } while(origem < 1 || origem > 3);
    if (6 - origem == 3) {
        do {
            printf("Informe a haste de Destino(1=A ou 2=B): ");
            scanf("%d", &destino);
        } while(destino != 1 && destino != 2);
    }
    else if (6 - origem == 4) {
        do {
            printf("Informe a haste de Destino(1=A ou 3=C):\t");
            scanf("%d",&destino);
        }while(destino !=1 && destino != 3);
    }
    else {
        do {
            printf("Informe a haste de Destino(2=B ou 3=C):\t");
            scanf("%d",&destino);
        } while(destino != 2 && destino != 3);
    }
    printf("\nA qtde minima de movimentos e: %.0f", pow(2, qtde_discos) - 1);//INFORMA A QTDE MINIMA DE MOVIMENTOS
    INICIA_PILHAS(p, qtde_discos);
    aux = 6 - (origem + destino) - 1;
    origem--;
    destino--;
    CARREGA_PILHA(p, origem, qtde_discos);// CARREGA PILHA ORIGEM COM NUMERO DE DISCOS INFORMADO ACIMA
    printf("\nENTER PARA INICIAR...");
    getch();
    system("cls"); // LIMPA TELA
}

void INICIA_JOGO(TpPilha p) { // FUNCAO QUE DEFINE INICIO DO JOGO
    int qtde_discos, origem, destino, aux, escolha;

    do {
        switch (MENU(escolha)) {
            case 1:
                DADOS_INICIO(p, qtde_discos, origem, destino, aux);
                JOGO_AUTOMATICO(p, qtde_discos, origem, destino, aux); // CHAMA O JOGO AUTOMATICO, SE SELECIONADO ACIMA
                break;
            case 2:
                DADOS_INICIO(p, qtde_discos, origem, destino, aux);
                JOGO_MANUAL(p, qtde_discos origem, destino, aux); // CHAMA O JOGO MANUAL, SE SELECIONADO ACIMA
        }
    } while(escolha != 3);
}

int main() { // PROGRAMA PRINCIPAL
    TpPilha pilhas;

    INICIA_JOGO(pilhas);//VARIAVEL ESCOLHA � ALTERADA NA SUBROTINA "MENU"
}
