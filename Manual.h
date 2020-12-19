// ABNER J�COMO PELISSER
void MOVE_MANUAL (TpPilha &p, int origem, int destino, int &movimento) { // VERIFICA SE MOVIMENTO � V�LIDO E MOVE
    if (VAZIA(p, destino) != 1) { // SE A HASTE DESTINO (DESTE MOVIMENTO)N�O FOR VAZIA
        if (VAZIA(p, origem) !=1 ) { // SE A HASTE ORIGEM(DESTE MOVIMENTO) N�O FOR VAZIA
            if (ELEMENTO_TOPO(p, origem) < ELEMENTO_TOPO(p, destino)) {
                movimento++;
                IMPRIME_MOV(origem, destino, ELEMENTO_TOPO(p, origem), movimento);
                printf("\n");
                MOVE(p, origem, destino);
            }
            else {
                printf("Disco Origem(%d) eh maior que Destino(%d)\n", origem + 1, destino + 1);
            }
        }
        else {
            printf("Movimento invalido, nao ha disco na haste Origem(%d)\n", origem + 1);
        }
    }
    else if(VAZIA(p, origem) !=1) { // SE A HASTE ORIGEM(DESTE MOVIMENTO) N�O FOR VAZIA, ENTRA NESTE IF
        movimento++;
        IMPRIME_MOV(origem, destino, ELEMENTO_TOPO(p, origem), movimento);
        MOVE(p, origem, destino);
    }
    else {
        printf("Movimento invalido, nao ha disco na haste Origem(%d)\n", origem + 1);
    }
}

void SEL_MOVIMENTO(int &de, int &para, int movimento) { // INFORMA A HASTE DESTINO E HASTE ORIGEM, PARA O MOVIMENTO
    printf("------------ Movimento %d ------------", movimento+1);
    do { // SELECIONA A HASTE ORIGEM
        printf("\nMover de(1=A, 2=B ou 3=C): ");
        scanf("%d",&de);
    } while(de < 1 || de > 3);
    if(6 - de == 3) { // SE VERDADEIRO, O 3 FOI SELECIONADO
        do{
            printf("Para(1=A ou 2=B): ");
            scanf("%d", &para);
        }while(para != 1 && para != 2);
    }
    else if(6 - de == 4) { // SE VERDADEIRO, O 2 FOI SELECIONADO
        do {
            printf("Para(1=A ou 3=C): ");
            scanf("%d", &para);
        } while(para != 1 && para != 3);
    }
    else { // SE VERDADEIRO, O 1 FOI SELECIONADO
        do {
            printf("Para(2=B ou 3=C): ");
            scanf("%d", &para);
        } while(para != 2 && para != 3);
    }
    de--;
    para--;
}

void JOGADAS(int movimento, int qtde_discos) { // ESTATISTICA DAS JOGADAS NO MODO MANUAL
    printf("\n-----------= TRANSFERENCIA CONCLUIDA =-----------");
    if(movimento == pow(2, qtde_discos) - 1)
        printf("\nPARABENS, QTDE MINIMA ALCANCADA!!\n");
    else
        printf("\nPARABENS, POREM VOCE JOGOU %.0f JOGADAS A MAIS QUE A QTDE MINIMA\n", movimento - (pow(2, qtde_discos) - 1));
    printf("\n-Qtde minima de jogadas: %.0f\n-Suas jogadas: %d", pow(2, qtde_discos) - 1, movimento);
}

void JOGO_MANUAL(TpPilha &p, int qtde_discos, int origem, int destino, int aux) {
    int de, para, movimento=0;

    do {
        SEL_MOVIMENTO(de, para, movimento);
        MOVE_MANUAL(p, de, para, movimento);
    } while(CHEIA(p, destino, qtde_discos) != 1);
    JOGADAS(movimento, qtde_discos);
    getch();
    system("cls");
}
