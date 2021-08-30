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

TEST_CASE("Testa contagem de jogador retorna -1 se jogador invalido",
          "[single-file]") {
    int teste[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste, 3) == -1);
    REQUIRE(ContaMarcacao(teste, 0) == -1);
    REQUIRE(ContaMarcacao(teste, 4) == -1);
}

TEST_CASE("Testa contagem de jogador retorna 0 se campo vazio",
          "[single-file]") {
    int teste[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste, 1) == 0);
    REQUIRE(ContaMarcacao(teste, 2) == 0);
}

TEST_CASE("Testa contagem de jogador retorna 1 se uma marcacao",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste1, 1) == 1);
    REQUIRE(ContaMarcacao(teste1, 2) == 0);

    int teste2[3][3] = {
            {0, 2, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste2, 2) == 1);
    REQUIRE(ContaMarcacao(teste2, 1) == 0);

    int teste3[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste3, 1) == 1);
    REQUIRE(ContaMarcacao(teste3, 2) == 0);

    int teste4[3][3] = {
            {0, 0, 0},
            {0, 0, 2},
            {0, 0, 0}
    };

    REQUIRE(ContaMarcacao(teste4, 2) == 1);
    REQUIRE(ContaMarcacao(teste4, 1) == 0);
}

TEST_CASE("Testa contagem de jogador retorna 2 se duas marcacoes",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 2},
            {0, 0, 0},
            {0, 0, 2}
    };

    REQUIRE(ContaMarcacao(teste1, 1) == 1);
    REQUIRE(ContaMarcacao(teste1, 2) == 2);
}

TEST_CASE("Testa contagem de jogador retorna 3 se tres marcacoes",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 2},
            {0, 1, 0},
            {2, 0, 2}
    };

    REQUIRE(ContaMarcacao(teste1, 1) == 2);
    REQUIRE(ContaMarcacao(teste1, 2) == 3);
}

TEST_CASE("Testa 1 comeca",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 2},
            {0, 1, 0},
            {2, 0, 2}
    };

    REQUIRE(VerificaVelha(teste1) == -2);

    int teste2[3][3] = {
            {0, 0, 2},
            {0, 0, 0},
            {0, 0, 0}
    };

    REQUIRE(VerificaVelha(teste2) == -2);
}

TEST_CASE("Testa jogador não repete",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {2, 0, 1}
    };

    REQUIRE(VerificaVelha(teste1) == -2);

    int teste2[3][3] = {
            {1, 1, 1},
            {0, 0, 0},
            {2, 0, 0}
    };

    REQUIRE(VerificaVelha(teste2) == -2);
}

TEST_CASE("Testa coluna 1 toda 1 retorna 1",
          "[single-file]") {
    int teste1[3][3] = {
            {1, 0, 0},
            {1, 2, 0},
            {1, 0, 2}
    };

    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Testa coluna 1 toda 2 retorna 2",
          "[single-file]") {
    int teste1[3][3] = {
            {2, 0, 1},
            {2, 1, 0},
            {2, 0, 1}
    };

    REQUIRE(VerificaVelha(teste1) == 2);
}

// TEST_CASE("Testa velha", "[single-file]" ) {
//   int teste1[3][3]= {
//     { 2, 0, 1 },
//     { 2, 0, 1 },
//     { 0, 2, 1 }};
//
//   REQUIRE(VerificaVelha(teste1) == 1);
// }

