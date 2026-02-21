#include <iostream>  // Biblioteca para usar cin e cout
#include <algorithm> // Biblioteca para usar a função min()
using namespace std;

/*
    📌 RESUMO DO QUE O PROGRAMA FAZ:

    O programa recebe um número inteiro d (uma distância qualquer)
    e calcula qual é a menor distância até o múltiplo de 400 mais próximo.

    Ele verifica:
    - O múltiplo de 400 imediatamente ANTES de d
    - O múltiplo de 400 imediatamente DEPOIS de d

    Depois compara as duas distâncias e imprime a menor delas.
*/

int main() {

    // d = valor informado (distância atual)
    int d;
    cin >> d;

    // ================================
    // 🔹 Encontrando o múltiplo de 400 anterior
    // ================================

    /*
        Quando fazemos (d / 400), estamos fazendo divisão inteira.
        Divisão inteira descarta a parte decimal.

        Exemplo:
        Se d = 850
        850 / 400 = 2 (não 2.125, porque a parte decimal é descartada)

        Depois multiplicamos por 400:
        2 * 400 = 800

        Ou seja:
        Encontramos o maior múltiplo de 400 menor ou igual a d.
    */
    int ponto_antes = (d / 400) * 400;

    // Distância entre d e o múltiplo anterior
    int dist_antes = d - ponto_antes;

    // ================================
    // 🔹 Encontrando o múltiplo de 400 seguinte
    // ================================

    /*
        O próximo múltiplo de 400 é simplesmente
        o múltiplo anterior + 400.
    */
    int ponto_depois = ponto_antes + 400;

    // Distância entre o próximo múltiplo e d
    int dist_depois = ponto_depois - d;

    // ================================
    // 🔹 Comparando as duas distâncias
    // ================================

    /*
        Agora verificamos qual das duas distâncias é menor:
        - dist_antes  (distância até o múltiplo anterior)
        - dist_depois (distância até o próximo múltiplo)

        A função min() retorna o menor valor entre dois números.
    */
    cout << min(dist_antes, dist_depois) << endl;

    return 0; // Finaliza o programa corretamente
}