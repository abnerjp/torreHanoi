// ABNER J�COMO PELISSER
void MOVE_AUTOMATICO(TpPilha &p, int origem, int destino, int &movimento, int num_disco, int real_destino) {
    if (CHEIA(p, real_destino, num_disco) != 1) {//SE A HASTE DESTINO N�O ESTIVER CHEIA
        if (VAZIA(p, destino) != 1) { // SE A HASTE DESTINO (DESTE MOVIMENTO)N�O FOR VAZIA
            if (VAZIA(p, origem) != 1) { // SE A HASTE ORIGEM(DESTE MOVIMENTO) N�O FOR VAZIA
                if (ELEMENTO_TOPO(p, origem) < ELEMENTO_TOPO(p, destino)) {
                    movimento++;
                    IMPRIME_MOV(origem, destino, ELEMENTO_TOPO(p, origem), movimento);
                    MOVE(p, origem, destino);
                }
                else {
                    movimento++;
                    IMPRIME_MOV(destino, origem, ELEMENTO_TOPO(p, destino), movimento);
                    MOVE(p, destino, origem);
                }
            }
            else {
                movimento++;
                IMPRIME_MOV(destino, origem, ELEMENTO_TOPO(p, destino), movimento);
                MOVE(p, destino, origem);
            }
        }
        else {
            if (VAZIA(p, origem) != 1) {
                movimento++;
                IMPRIME_MOV(origem, destino, ELEMENTO_TOPO(p, origem), movimento);
                MOVE(p, origem, destino);
            }
        }
    }
}

void JOGO_AUTOMATICO(TpPilha &p, int qtde_discos, int origem, int destino, int aux) {
    int movimento = 0;
    if (qtde_discos % 2 == 0) { // SEQUENCIA DE JOGADAS PARA QTDE PAR
        while (CHEIA(p, destino, qtde_discos) != 1) {// MOVIMENTOS PARA QTDE DE DISCOS PAR(A:B, A:C,
            MOVE_AUTOMATICO(p, origem, aux, movimento, qtde_discos, destino);
            MOVE_AUTOMATICO(p, origem, destino, movimento, qtde_discos, destino);
            MOVE_AUTOMATICO(p, aux, destino, movimento, qtde_discos, destino);
        }
    }
    else if (qtde_discos % 2 != 0) { // SEQUENCIA DE JOGADAS PARA QTDE IMPAR
        while (CHEIA(p, destino, qtde_discos) != 1) {
            MOVE_AUTOMATICO(p, origem, destino, movimento, qtde_discos, destino);
            MOVE_AUTOMATICO(p, origem, aux, movimento, qtde_discos, destino);
            MOVE_AUTOMATICO(p, destino, aux, movimento, qtde_discos, destino);
        }
    }
    printf("\n-= PRESSIONE QUALQUER TECLA PARA CONTINUAR =-");
    getch();
    system("cls");
}
