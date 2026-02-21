#include <iostream> // Biblioteca para entrada e saída (cin e cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Temos:
    - e elementos (ex: estudantes)
    - m pares que devem ficar JUNTOS
    - d pares que devem ficar SEPARADOS

    Os elementos são divididos em grupos de 3.

    O programa:
    1) Lê as regras (quem quer ficar junto e separado).
    2) Lê como os grupos foram formados.
    3) Conta quantas regras foram violadas.
    4) Imprime o total de violações.

    🔹 Violação acontece quando:
       - Um par "juntos" está em grupos diferentes.
       - Um par "separados" está no mesmo grupo.
*/

// Tamanho máximo dos vetores (grande o suficiente)
const int MAX = 1000010;

// juntos[i] guarda um par que DEVE ficar junto
int juntos[MAX][2];

// separados[i] guarda um par que DEVE ficar separado
int separados[MAX][2];

// grupo[x] guarda o número do grupo ao qual x pertence
int grupo[MAX];

int main() {

    // e = total de elementos
    // m = quantidade de regras "juntos"
    // d = quantidade de regras "separados"
    int e, m, d;
    cin >> e >> m >> d;

    // ================================
    // 🔹 Leitura das regras "juntos"
    // ================================
    for (int i = 1; i <= m; i++) {
        cin >> juntos[i][0] >> juntos[i][1];
    }

    // ==================================
    // 🔹 Leitura das regras "separados"
    // ==================================
    for (int i = 1; i <= d; i++) {
        cin >> separados[i][0] >> separados[i][1];
    }

    // ================================
    // 🔹 Leitura da formação dos grupos
    // ================================
    /*
        Cada grupo possui exatamente 3 elementos.
        Logo, teremos e/3 grupos.

        Para cada grupo i,
        marcamos no vetor grupo[] que
        aqueles três elementos pertencem ao grupo i.
    */
    for (int i = 1; i <= e / 3; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        grupo[a] = i;
        grupo[b] = i;
        grupo[c] = i;
    }

    // ================================
    // 🔹 Contagem de violações
    // ================================

    int resp = 0; // total de regras quebradas

    // Verifica pares que deveriam estar juntos
    for (int i = 1; i <= m; i++) {

        int x = juntos[i][0];
        int y = juntos[i][1];

        // Se estiverem em grupos diferentes → violação
        if (grupo[x] != grupo[y]) {
            resp++;
        }
    }

    // Verifica pares que deveriam estar separados
    for (int i = 1; i <= d; i++) {

        int x = separados[i][0];
        int y = separados[i][1];

        // Se estiverem no mesmo grupo → violação
        if (grupo[x] == grupo[y]) {
            resp++;
        }
    }

    // Imprime o número total de violações
    cout << resp << endl;

    return 0; // Programa finalizado corretamente
}