#define X 1
#define O 2

#define JOGO_EMPATADO 0
#define JOGO_INDEFINIDO -1
#define JOGO_INVALIDO -2


int VerificaVelha(int velha[3][3]);
int ContaMarcacao(const int velha[3][3], int jogador);

/* Funções de uso interno */
bool XComecou(const int velha[3][3]);
bool JogadorRepetiu(const int velha[3][3]);
bool HaJogadasSuficientesParaGanhar(const int velha[3][3]);
bool EstaMarcado(const int velha[3][3], int linha, int coluna = 0);
bool LinhaETodaIgual(const int velha[3][3], int linha);
bool ColunaETodaIgual(const int velha[3][3], int coluna);
bool OJogouDepoisDePerder(const int velha[3][3], int ganhador);
bool DiagonalPrincipalEIgual(const int velha[3][3]);
bool DiagonalSecundariaEIgual(const int velha[3][3]);

