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
    for (int i = 0; i < 3; i++)
        if (velha[i][0] == 1
                && velha[i][0] == velha[i][1]
                && velha[i][1] == velha[i][2])
            return 1;
    return -1;
}
