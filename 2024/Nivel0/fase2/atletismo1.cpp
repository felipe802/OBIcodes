#include <iostream> // Biblioteca para usar cin e cout
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa resolve um problema de ranking.

    Entrada:
    - Um número n (quantidade de atletas)
    - Depois, n números representando os atletas
      na ordem do ranking (do 1º ao n-ésimo lugar)

    Objetivo:
    Descobrir em qual posição cada atleta ficou.

    🔹 Ideia principal:
    Se sabemos que na posição 1 está o atleta X,
    então podemos guardar:

        posicao_no_ranking[X] = 1

    Assim, criamos um "mapa inverso":
    - Entrada → posição → atleta
    - Saída   → atleta → posição
*/

// Definimos um tamanho máximo para o vetor
const int MAXN = 100100;

// posicao_no_ranking[i] vai guardar
// em qual posição o atleta i ficou
int posicao_no_ranking[MAXN];

int main() {

    // n = quantidade de atletas
    int n;
    cin >> n;

    /*
        Leitura do ranking.

        A variável "posicao" representa
        a posição atual no ranking (1º, 2º, 3º, ...).

        Para cada posição, lemos qual atleta está nela.
    */
    for (int posicao = 1; posicao <= n; posicao++) {

        int atleta;
        cin >> atleta;

        // Guardamos que esse atleta ficou nessa posição
        posicao_no_ranking[atleta] = posicao;
    }

    /*
        Agora queremos imprimir a posição
        de cada atleta de 1 até n.
    */
    for (int atleta = 1; atleta <= n; atleta++) {

        cout << posicao_no_ranking[atleta] << endl;
    }

    return 0; // Finaliza o programa corretamente
}