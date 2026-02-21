#include <bits/stdc++.h> // Inclui praticamente todas as bibliotecas padrão
using namespace std;

/*
    📌 OBI 2022 – Fase 2
    🏆 Tarefa: Pirâmide

    💡 Ideia da solução:

    Para cada posição (i, j) da matriz n x n,
    queremos descobrir a qual "camada" ela pertence.

    A camada é definida pela MENOR distância
    até qualquer uma das quatro bordas.

    Distâncias possíveis:
        - até o topo        → i
        - até a base        → n + 1 - i
        - até a esquerda    → j
        - até a direita     → n + 1 - j

    O valor da célula será o menor desses quatro valores.
*/

const int MAXN = 110;  // Não é necessário aqui, mas mantido por padrão
int mat[MAXN][MAXN];   // Também não é usada diretamente

int main() {

    int n;
    scanf("%d", &n); // Lê o tamanho da matriz

    // Percorre cada linha
    for (int i = 1; i <= n; i++) {

        // Percorre cada coluna
        for (int j = 1; j <= n; j++) {

            // Calcula as distâncias até as bordas
            int cima = i;
            int baixo = n + 1 - i;
            int esq = j;
            int dir = n + 1 - j;

            // O valor da posição é a menor distância
            int valor = min(min(cima, baixo), min(esq, dir));

            printf("%d ", valor);
        }

        printf("\n"); // Quebra de linha ao final da linha
    }

    return 0; // Programa finalizado corretamente
}