#include <iostream> // Biblioteca para entrada e saída
using namespace std;

// Definimos um tamanho máximo grande o suficiente
const int MAX = 1000010;

// juntos[i][0] e juntos[i][1] guardam um par que DEVE ficar junto
int juntos[MAX][2];

// separados[i][0] e separados[i][1] guardam um par que DEVE ficar separado
int separados[MAX][2];

// grupo[x] guarda em qual grupo o elemento x está
int grupo[MAX];

int main() {

    // e = quantidade total de elementos
    // m = quantidade de pares que devem ficar juntos
    // d = quantidade de pares que devem ficar separados
    int e, m, d;
    cin >> e >> m >> d;

    // Lê os pares que devem ficar juntos
    for (int i = 1; i <= m; i++) {
        cin >> juntos[i][0] >> juntos[i][1];
    }

    // Lê os pares que devem ficar separados
    for (int i = 1; i <= d; i++) {
        cin >> separados[i][0] >> separados[i][1];
    }

    // Agora lemos os grupos
    // Cada grupo tem exatamente 3 elementos
    // Portanto, teremos e/3 grupos
    for (int i = 1; i <= e / 3; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        // Marcamos que os três pertencem ao grupo i
        grupo[a] = i;
        grupo[b] = i;
        grupo[c] = i;
    }

    // resp = quantidade de regras que foram violadas
    int resp = 0;

    // Verifica as regras "juntos"
    // Se dois que deveriam estar juntos estão em grupos diferentes → erro
    for (int i = 1; i <= m; i++) {

        int x = juntos[i][0];
        int y = juntos[i][1];

        if (grupo[x] != grupo[y]) {
            resp++;
        }
    }

    // Verifica as regras "separados"
    // Se dois que deveriam estar separados estão no mesmo grupo → erro
    for (int i = 1; i <= d; i++) {

        int x = separados[i][0];
        int y = separados[i][1];

        if (grupo[x] == grupo[y]) {
            resp++;
        }
    }

    // Imprime o total de regras violadas
    cout << resp << endl;

    return 0; // Finaliza o programa
}