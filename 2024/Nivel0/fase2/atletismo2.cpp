#include <iostream> // Para usar cin e cout
#include <map>      // Para usar a estrutura map
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe um ranking de atletas.

    Entrada:
    - Um número n (quantidade de atletas)
    - Depois, n números representando os atletas
      na ordem do ranking (1º lugar até n-ésimo lugar)

    Objetivo:
    Mostrar em qual posição cada atleta ficou.

    🔹 Diferença desta versão:
    Em vez de usar vetor, usamos um map<int, int>.

    O map funciona como um "dicionário":
    - Chave   → número do atleta
    - Valor   → posição dele no ranking

    Exemplo:
    Se atleta 7 ficou na posição 2:
        posicao_no_ranking[7] = 2
*/

// Criamos um map onde:
// chave  = número do atleta
// valor  = posição no ranking
map<int, int> posicao_no_ranking;

int main() {

    // n = quantidade de atletas
    int n;
    cin >> n;

    /*
        Lemos o ranking na ordem das posições.

        A variável "posicao" representa:
        1º, 2º, 3º, ..., n-ésimo lugar.
    */
    for (int posicao = 1; posicao <= n; posicao++) {

        int atleta;
        cin >> atleta;

        // Guardamos no map que esse atleta
        // ficou nessa posição
        posicao_no_ranking[atleta] = posicao;
    }

    /*
        Agora queremos imprimir a posição
        de cada atleta de 1 até n.

        Como usamos map, acessamos assim:
            posicao_no_ranking[atleta]
    */
    for (int atleta = 1; atleta <= n; atleta++) {

        cout << posicao_no_ranking[atleta] << endl;
    }

    return 0; // Finaliza o programa corretamente
}