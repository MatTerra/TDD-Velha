// Copyright 2021 Mateus Terra
/**
 * \file  velha.cpp
 */


#include "velha.hpp"

bool EstaMarcado(const int velha[3][3], int linha, int coluna = 0);

bool LinhaETodaIgual(const int velha[3][3], int linha);

bool XComecou(const int velha[3][3]);

bool JogadorRepetiu(const int velha[3][3]);

bool ColunaETodaIgual(const int velha[3][3], int coluna);

bool OJogouDepoisDePerder(const int velha[3][3], int ganhador);

/**
 * @brief Verifica situacao do jogo da velha
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 */
int VerificaVelha(int velha[3][3]) {
    if (!XComecou(velha) || JogadorRepetiu(velha))
        return -2;

    int ganhador = -1;
    for (int linha = 0; linha < 3; linha++)
        if (EstaMarcado(velha, linha)
                && LinhaETodaIgual(velha, linha))
            ganhador = velha[linha][0];

    for (int coluna = 0; coluna < 3; coluna++)
        if (EstaMarcado(velha, 0, coluna)
                && ColunaETodaIgual(velha, coluna))
            ganhador = velha[0][coluna];

    if (OJogouDepoisDePerder(velha, ganhador))
        return -2;

    return ganhador;
}

bool XComecou(const int velha[3][3]) {
    return ContaMarcacao(velha, X) >= ContaMarcacao(velha, O);
}

bool JogadorRepetiu(const int velha[3][3]) {
    return ContaMarcacao(velha, X) - ContaMarcacao(velha, O) > 1;
}

bool EstaMarcado(const int velha[3][3], int linha, int coluna) {
    return velha[linha][coluna] > 0;
}

bool LinhaETodaIgual(const int velha[3][3], int linha) {
    return velha[linha][0] == velha[linha][1]
           && velha[linha][1] == velha[linha][2];
}

bool ColunaETodaIgual(const int velha[3][3], int coluna) {
    return velha[0][coluna] == velha[1][coluna]
           && velha[1][coluna] == velha[2][coluna];
}

bool OJogouDepoisDePerder(const int velha[3][3], int ganhador) {
    return ganhador == X
           && ContaMarcacao(velha, X) == ContaMarcacao(velha, O);
}

int ContaMarcacao(const int velha[3][3], int jogador) {
    if (jogador < X || jogador > O )
        return -1;

    int contagem = 0;
    for (int linha = 0; linha < 3; linha++)
        for (int coluna = 0; coluna < 3; coluna ++)
            if (velha[linha][coluna] == jogador)
                contagem++;

    return contagem;
}
