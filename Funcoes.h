// ABNER J�COMO PELISSER
struct TpPilha {
    int pilha[MAXPILHA], base[MAXPILHA], topo[MAXPILHA];
};

void INICIA_PILHAS(TpPilha &p, int num_disco) {//INICIA AS PILHAS(QTDE_PILHA) PARA TORRE DE HANOI, DEFININDO AS BASES E TOPOS DE CADA UMA
    int i;
    for(i = 0;i < QTDE_PILHA; i++) {
        p.base[i] = num_disco * i;
        p.topo[i] = p.base[i] - 1;
    }
}

int RETIRA(TpPilha &p, int np) { //RETIRA ELEMENTO DO TOPO DA PILHA APONTADA POR "NP"
   return p.pilha[p.topo[np]--];
}

void INSERE(TpPilha &p, int elem, int np) { // INSERE ELEMENTO NA PILHA ESCOLHIDA
    p.pilha[++p.topo[np]] = elem;
}

int ELEMENTO_TOPO(TpPilha p, int np) { //RETORNA O ELEMENTO DO TOPO DA PILHA
    return p.pilha[p.topo[np]];
}

char CHEIA(TpPilha p, int np, int num_disco) { // VERIFICA SE DETERMINADA PILHA ESTA CHEIA
    return p.topo[np] + 1 == p.base[np] + num_disco;
}

char VAZIA(TpPilha p, int np) { // VERIFICA SE DETERMINADA PILHA ESTA VAZIA
    return p.topo[np] + 1 == p.base[np];
}

void EXIBE(TpPilha p, int np) { // EXIBE PILHA INDICADA POR "NP"
    while (p.topo[np] >= p.base[np]) {
        printf("%d\n", ELEMENTO_TOPO(p, np));
        RETIRA(p, np);
    }
}

void MOVE(TpPilha &p, int npOrigem, int npDestino) { // MOVE VALORES DE UMA PILHA(ORIGEM) PARA OUTRA (DESTINO)
    INSERE(p, RETIRA(p, npOrigem), npDestino);
}

void CARREGA_PILHA(TpPilha &p, int origem, int num_discos){ // CARREGA PILHA(ORIGEM SELECIONADA) DE ACORDO COM A QTDE DE DISCO INFORMADA
    int i, j = num_discos;
    for(i = 0; i < num_discos; i++){
        INSERE(p, --j + 1, origem);
    }
}

void IMPRIME_MOV(int de, int para, int elemento, int movimento){// IMPRIME OS MOVIMENTOS NA TELA
    char haste[]={'A', 'B', 'C'};
    printf("%d - Mova disco %d de %c para %c\n", movimento, elemento, haste[de], haste[para]);
}
