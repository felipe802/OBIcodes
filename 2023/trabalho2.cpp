#include <iostream> // Biblioteca para entrada e saída (cin e cout)
using namespace std;

// Definimos um tamanho máximo para os vetores
// Valor grande o suficiente para os limites do problema
const int MAXN = 1000100;

// grupo[x] -> guarda o número do grupo ao qual o estudante x pertence
int grupo[MAXN];

// juntos[i][0] e juntos[i][1]
// Guardam pares de estudantes que querem estar no MESMO grupo
int juntos[MAXN][2];

// separados[i][0] e separados[i][1]
// Guardam pares de estudantes que querem estar em GRUPOS DIFERENTES
int separados[MAXN][2];

int main() {

    // E = número total de estudantes
    // M = número de pares que querem ficar juntos
    // D = número de pares que querem ficar separados
    int E, M, D;
    cin >> E >> M >> D;

    // Leitura dos pares que querem ficar juntos
    for (int i = 1; i <= M; i++) {
        cin >> juntos[i][0] >> juntos[i][1];
    }

    // Leitura dos pares que querem ficar separados
    for (int i = 1; i <= D; i++) {
        cin >> separados[i][0] >> separados[i][1];
    }

    // Leitura dos grupos
    // Como cada grupo tem exatamente 3 estudantes,
    // teremos E/3 grupos
    for (int i = 1; i <= E / 3; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        // Marcamos os três estudantes como pertencentes ao grupo i
        grupo[a] = i;
        grupo[b] = i;
        grupo[c] = i;
    }

    // Variável que vai contar quantas regras foram violadas
    int num_violacoes = 0;

    // Verificando os pares que querem ficar juntos
    // Se estiverem em grupos diferentes, é violação
    for (int i = 1; i <= M; i++) {

        int a = juntos[i][0];
        int b = juntos[i][1];

        if (grupo[a] != grupo[b]) {
            num_violacoes++;
        }
    }

    // Verificando os pares que querem ficar separados
    // Se estiverem no mesmo grupo, é violação
    for (int i = 1; i <= D; i++) {

        int a = separados[i][0];
        int b = separados[i][1];

        if (grupo[a] == grupo[b]) {
            num_violacoes++;
        }
    }

    // Imprime o total de violações encontradas
    cout << num_violacoes << endl;

    return 0; // Indica que o programa terminou corretamente
}