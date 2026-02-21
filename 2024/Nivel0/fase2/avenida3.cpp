#include <iostream> // Biblioteca para entrada e saída
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe um número inteiro d (entre 0 e 2000).

    Ele quer calcular a MENOR distância entre d
    e algum múltiplo de 400.

    Os múltiplos de 400 nesse intervalo são:
    0, 400, 800, 1200, 1600, 2000

    A lógica usada aqui divide o intervalo total em "faixas".
    Cada faixa está entre dois múltiplos consecutivos de 400.

    Dentro de cada faixa:
    - Ou d está mais perto do múltiplo anterior
    - Ou está mais perto do próximo múltiplo

    O código decide isso usando várias condições (if / else if).
*/

int main() {

    // d = valor informado
    int d;
    cin >> d;

    // resp = guardará a menor distância até um múltiplo de 400
    int resp;

    /*
        Cada bloco abaixo trata um intervalo específico:

        Exemplo:
        Se d está entre 0 e 400:
            - Se d <= 200 → está mais perto de 0
            - Se d > 200  → está mais perto de 400

        O mesmo padrão se repete para os outros intervalos.
    */

    if (d <= 200)               // Mais perto de 0
        resp = d;

    else if (d <= 400)          // Mais perto de 400
        resp = 400 - d;

    else if (d <= 600)          // Mais perto de 400
        resp = d - 400;

    else if (d <= 800)          // Mais perto de 800
        resp = 800 - d;

    else if (d <= 1000)         // Mais perto de 800
        resp = d - 800;

    else if (d <= 1200)         // Mais perto de 1200
        resp = 1200 - d;

    else if (d <= 1400)         // Mais perto de 1200
        resp = d - 1200;

    else if (d <= 1600)         // Mais perto de 1600
        resp = 1600 - d;

    else if (d <= 1800)         // Mais perto de 1600
        resp = d - 1600;

    else                        // Caso final: mais perto de 2000
        resp = 2000 - d;

    // Imprime a menor distância encontrada
    cout << resp << endl;

    return 0; // Finaliza o programa corretamente
}