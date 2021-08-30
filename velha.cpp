// Copyright 2021 Mateus Terra
/**
 * \file  velha.cpp
 */


#include "velha.hpp"

bool EstaMarcado(const int velha[3][3], int linha, int coluna = 0);

bool LinhaETodaIgual(const int velha[3][3], int linha);

/**
 * @brief Verifica situacao do jogo da velha
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 */
int VerificaVelha(int velha[3][3]) {
    for (int linha = 0; linha < 3; linha++)
        if (EstaMarcado(velha, linha)
                && LinhaETodaIgual(velha, linha))
            return velha[linha][0];
    return -1;
}

bool LinhaETodaIgual(const int velha[3][3], int linha) {
    return velha[linha][0] == velha[linha][1]
        && velha[linha][1] == velha[linha][2];
}

bool EstaMarcado(const int velha[3][3], int linha, int coluna) {
    return velha[linha][coluna] > 0;
}

int ContaMarcacao(const int velha[3][3], int jogador) {
    if (jogador < 1 || jogador > 2 )
        return -1;
    for (int coluna = 0; coluna < 3; coluna ++)
        if (velha[0][coluna] == jogador)
            return 1;
    for (int coluna = 0; coluna < 3; coluna ++)
        if (velha[1][coluna] == jogador)
            return 1;
    return 0;
}
