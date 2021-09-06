// Copyright 2021 Mateus Terra
/**
 * \file  velha.cpp
 */

#include "velha.hpp"


/**
 * @brief Verifica situacao do jogo da velha
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha. Caso o
 * jogo seja inválido, retorna JOGO_INVALIDO.
 * Caso o jogo ainda não possua jogadas
 * suficientes para estar definido retorna
 * JOGO_INDEFINIDO. Caso o jogo possua jogadas
 * suficientes mas está empatado, retorna
 * JOGO_EMPATADO. Caso X tenha ganhado, retorna
 * X. Caso O tenha ganhado, retorna O.
 */
int VerificaVelha(int velha[3][3]) {
    if (!XComecou(velha)
            || JogadorRepetiu(velha)
            || !PossuiApenasMarcacoesValidas(velha))
        return JOGO_INVALIDO;

    if (!HaJogadasSuficientesParaGanhar(velha))
        return JOGO_INDEFINIDO;

    int ganhador = JOGO_EMPATADO;
    for (int linha = 0; linha < 3; linha++)
        if (EstaMarcado(velha, linha)
                && LinhaETodaIgual(velha, linha))
            ganhador = velha[linha][0];

    for (int coluna = 0; coluna < 3; coluna++)
        if (EstaMarcado(velha, 0, coluna)
                && ColunaETodaIgual(velha, coluna))
            ganhador = velha[0][coluna];

    if (EstaMarcado(velha, 1, 1)
            && (DiagonalPrincipalEIgual(velha)
                || DiagonalSecundariaEIgual(velha)))
        ganhador = velha[1][1];

    if (OJogouDepoisDePerder(velha, ganhador))
        return JOGO_INVALIDO;

    return ganhador;
}

/**
 * @brief Verifica se o X começou
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna true se a quantidade de marcações X é
 * maior ou igual a quantidade de marcações O.
 */
bool XComecou(const int velha[3][3]) {
    return ContaMarcacao(velha, X) >= ContaMarcacao(velha, O);
}

/**
 * @brief Verifica se algum jogador repetiu
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna true se a diferença entre a quantidade
 * de marcações X e a quantidade de marcações O é
 * maior que 1.
 */
bool JogadorRepetiu(const int velha[3][3]) {
    return ContaMarcacao(velha, X) - ContaMarcacao(velha, O) > 1;
}

/**
 * @brief Verifica se algum jogador já possui 3
 * marcações
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna true se o jogador X possui 3 no
 * tabuleiro.
 */
bool HaJogadasSuficientesParaGanhar(const int velha[3][3]) {
    return ContaMarcacao(velha, X) >= 3;
}

/**
 * @brief Verifica se a posição (linha, coluna)
 * está marcada
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 * @param linha Linha a ser analisada
 * @param coluna Coluna a ser analisada
 *
 * Analisa uma posicao de um tabuleiro de jogo da
 * velha e retorna se ela está marcada, isto é,
 * possui valor maior que 0.
 */
bool EstaMarcado(const int velha[3][3], int linha, int coluna) {
    return velha[linha][coluna] > 0;
}

/**
 * @brief Verifica se a linha possui todas as
 * colunas iguais
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 * @param linha Linha a ser analisada
 *
 * Analisa uma linha de um tabuleiro de jogo da
 * velha e retorna true se todas suas marcações
 * são iguais.
 */
bool LinhaETodaIgual(const int velha[3][3], int linha) {
    return velha[linha][0] == velha[linha][1]
           && velha[linha][1] == velha[linha][2];
}

/**
 * @brief Verifica se a coluna possui todas as
 * linhas iguais
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 * @param coluna Coluna a ser analisada
 *
 * Analisa uma coluna de um tabuleiro de jogo da
 * velha e retorna true se todas suas marcações
 * são iguais.
 */
bool ColunaETodaIgual(const int velha[3][3], int coluna) {
    return velha[0][coluna] == velha[1][coluna]
           && velha[1][coluna] == velha[2][coluna];
}

/**
 * @brief Verifica se a diagonal principal possui
 * todas as marcações iguais
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa a diagonal principal de um tabuleiro
 * de jogo da velha e retorna true se todas suas
 * marcações são iguais.
 */
bool DiagonalPrincipalEIgual(const int velha[3][3]) {
    return velha[0][0] == velha[1][1]
           && velha[1][1] == velha[2][2];
}

/**
 * @brief Verifica se a diagonal secundária
 * possui todas as marcações iguais
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 *
 * Analisa a diagonal secundária de um tabuleiro
 * de jogo da velha e retorna true se todas suas
 * marcações são iguais.
 */
bool DiagonalSecundariaEIgual(const int velha[3][3]) {
    return velha[0][2] == velha[1][1]
           && velha[1][1] == velha[2][0];
}

/**
 * @brief Verifica se X venceu e possui um número
 * de marcações igual a O
 * @author Mateus Berardo de Souza Terra
 * @param  velha Jogo a ser analisado
 * @param ganhador Ganhador do jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna true se X venceu o jogo e O possui um
 * número de marcações iguais a X, pois o X joga
 * primeiro.
 */
bool OJogouDepoisDePerder(const int velha[3][3], int ganhador) {
    return ganhador == X
           && ContaMarcacao(velha, X) == ContaMarcacao(velha, O);
}

/**
 * @brief Conta a quantidade de marcações do
 * jogador
 * @author Mateus Berardo de Souza Terra
 * @param velha Jogo a ser analisado
 * @param jogador Jogador para contar as
 * marcações
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna a quantidade de marcações do jogador
 * solicitado. Caso o jogador não seja X ou O,
 * retorna -1.
 */
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

/**
 * @brief Verifica se há alguma marcacao invalida
 * @author Mateus Berardo de Souza Terra
 * @param velha Jogo a ser analisado
 *
 * Analisa um tabuleiro de jogo da velha e
 * retorna true se todas as marcacoes sao validas.
 */
bool PossuiApenasMarcacoesValidas(const int velha[3][3]) {
    for (int linha = 0; linha < 3; linha++)
        for (int coluna = 0; coluna < 3; coluna ++)
            if (velha[linha][coluna] < 0 || velha[linha][coluna] > 2)
                return false;

    return true;
}
