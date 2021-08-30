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
 */
int VerificaVelha(int velha[3][3]) {
    if (velha[0][0] == 1
            && velha[0][0] == velha[0][1]
            && velha[0][1] == velha[0][2])
        return 1;
    return -1;
}
