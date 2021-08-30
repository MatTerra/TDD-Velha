// Copyright 2021 Mateus Terra
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"


TEST_CASE("Testa jogo em branco deve ser -1", "[single-file]") {
    int teste[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(VerificaVelha(teste) == -1);
}

TEST_CASE("Testa primeira linha toda 1 deve retornar 1", "[single-file]") {
    int teste[3][3] = {
            {1, 1, 1},
            {0, 2, 0},
            {2, 0, 0}
    };

    REQUIRE(VerificaVelha(teste) == 1);
}

TEST_CASE("Testa segunda linha toda 1 deve retornar 1", "[single-file]") {
    int teste[3][3] = {
            {0, 2, 0},
            {1, 1, 1},
            {2, 0, 0}
    };

    REQUIRE(VerificaVelha(teste) == 1);
}

TEST_CASE("Testa segunda linha toda 2 deve retornar 2", "[single-file]") {
    int teste[3][3] = {
            {0, 1, 1},
            {2, 2, 2},
            {1, 0, 0}
    };

    REQUIRE(VerificaVelha(teste) == 2);
}

TEST_CASE("Testa terceira linha toda 2 deve retornar 2", "[single-file]") {
    int teste[3][3] = {
            {0, 1, 1},
            {1, 0, 0},
            {2, 2, 2}
    };

    REQUIRE(VerificaVelha(teste) == 2);
}

// TEST_CASE("Testa velha", "[single-file]" ) {
//   int teste1[3][3]= {
//     { 2, 0, 1 },
//     { 2, 0, 1 },
//     { 0, 2, 1 }};
//
//   REQUIRE(VerificaVelha(teste1) == 1);
// }

