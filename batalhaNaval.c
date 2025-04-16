#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha, coluna)
    int linhaNavio1 = 2; // Navio horizontal
    int colunaNavio1 = 4;

    int linhaNavio2 = 5; // Navio vertical
    int colunaNavio2 = 7;

    // Validação: verificar se os navios cabem e não se sobrepõem
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        
        // Posicionar navio 1 (horizontal)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
        }

        // Verificar sobreposição antes de posicionar navio 2
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio 2
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
            }

            // Exibição do tabuleiro
            printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }

        } else {
            printf("Erro: os navios estão se sobrepondo! Mude as coordenadas.\n");
        }

    } else {
        printf("Erro: os navios ultrapassam os limites do tabuleiro!\n");
    }

    return 0;
}
