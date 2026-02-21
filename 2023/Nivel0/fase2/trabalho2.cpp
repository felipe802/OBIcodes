#include <iostream> // Biblioteca para entrada e saída (cin e cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Temos E estudantes que serão divididos em grupos de 3 pessoas.

    Também existem:
    - M pares de estudantes que querem ficar no MESMO grupo.
    - D pares de estudantes que querem ficar em GRUPOS DIFERENTES.

    O programa:
    1) Lê todas as regras (juntos e separados).
    2) Lê a formação dos grupos.
    3) Verifica quantas regras foram violadas.
    4) Imprime o número total de violações.

    🔹 Regra violada:
       - Par "juntos" em grupos diferentes.
       - Par "separados" no mesmo grupo.
*/

// Tamanho máximo dos vetores (grande o suficiente para o problema)
const int MAXN = 1000100;

// grupo[x] guarda o número do grupo ao qual o estudante x pertence
int grupo[MAXN];

// juntos[i] guarda um par que quer ficar junto
int juntos[MAXN][2];

// separados[i] guarda um par que quer ficar separado
int separados[MAXN][2];

int main() {

    // E = número total de estudantes
    // M = quantidade de pares que querem ficar juntos
    // D = quantidade de pares que querem ficar separados
    int E, M, D;
    cin >> E >> M >> D;

    // ================================
    // 🔹 Leitura das regras "juntos"
    // ================================
    for (int i = 1; i <= M; i++) {
        cin >> juntos[i][0] >> juntos[i][1];
    }

    // ==================================
    // 🔹 Leitura das regras "separados"
    // ==================================
    for (int i = 1; i <= D; i++) {
        cin >> separados[i][0] >> separados[i][1];
    }

    // ================================
    // 🔹 Leitura dos grupos formados
    // ================================
    /*
        Cada grupo possui exatamente 3 estudantes.
        Portanto, teremos E/3 grupos.

        Para cada grupo i,
        marcamos no vetor grupo[] que aqueles
        estudantes pertencem ao grupo i.
    */
    for (int i = 1; i <= E / 3; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        grupo[a] = i;
        grupo[b] = i;
        grupo[c] = i;
    }

    // ================================
    // 🔹 Verificação das violações
    // ================================

    int num_violacoes = 0;

    // Verifica pares que deveriam estar juntos
    for (int i = 1; i <= M; i++) {

        int a = juntos[i][0];
        int b = juntos[i][1];

        // Se estão em grupos diferentes → violação
        if (grupo[a] != grupo[b]) {
            num_violacoes++;
        }
    }

    // Verifica pares que deveriam estar separados
    for (int i = 1; i <= D; i++) {

        int a = separados[i][0];
        int b = separados[i][1];

        // Se estão no mesmo grupo → violação
        if (grupo[a] == grupo[b]) {
            num_violacoes++;
        }
    }

    // ================================
    // 🔹 Saída final
    // ================================
    cout << num_violacoes << endl;

    return 0; // Programa finalizado com sucesso
}