#include <iostream>   // Para usar cin e cout
#include <algorithm>  // Para usar a função min()
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe um número inteiro d.

    Ele quer descobrir qual é a menor distância entre d
    e qualquer múltiplo de 400 dentro do intervalo [0, 2000].

    Para isso:
    - Percorre todos os múltiplos de 400 (0, 400, 800, ..., 2000)
    - Calcula a distância entre d e cada um deles
    - Guarda a menor distância encontrada
    - Imprime essa menor distância no final
*/

int main() {

    // d = valor informado
    int d;
    cin >> d;

    // resp = guardará a menor distância encontrada
    // Começamos com um valor grande (2000)
    // Assim garantimos que qualquer distância real será menor
    int resp = 2000;

    /*
        Percorremos todos os múltiplos de 400
        começando em 0 até 2000.
        
        ponto assume os valores:
        0, 400, 800, 1200, 1600, 2000
    */
    for (int ponto = 0; ponto <= 2000; ponto += 400) {

        // Vamos calcular a distância entre d e esse múltiplo
        int dist_ponto;

        /*
            Distância é o valor absoluto da diferença.
            Como não estamos usando abs(), fazemos manualmente:

            Se d > ponto → distância = d - ponto
            Senão → distância = ponto - d
        */
        if (d > ponto)
            dist_ponto = d - ponto;
        else
            dist_ponto = ponto - d;

        // Atualizamos a menor distância encontrada até agora
        resp = min(resp, dist_ponto);
    }

    // Imprime a menor distância encontrada
    cout << resp << endl;

    return 0; // Indica que o programa terminou corretamente
}