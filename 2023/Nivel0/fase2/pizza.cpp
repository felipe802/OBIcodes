#include <iostream> // Biblioteca para entrada e saída (cin e cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Temos:
    - n → quantidade atual de pedaços disponíveis
    - g → quantidade de pizzas grandes (cada uma tem 8 pedaços)
    - m → quantidade de pizzas médias (cada uma tem 6 pedaços)

    O objetivo é:
    Calcular quantos pedaços ainda faltam para atingir
    o total necessário baseado nas pizzas pedidas.

    🔹 Se já houver pedaços suficientes → imprimir 0.
    🔹 Caso contrário → imprimir quantos pedaços faltam.
*/

int main() {

    // n = pedaços que já temos
    // g = número de pizzas grandes
    // m = número de pizzas médias
    int n, g, m;

    // Leitura dos valores
    cin >> n >> g >> m;

    /*
        Calculamos o total necessário:

        - Cada pizza grande tem 8 pedaços → 8 * g
        - Cada pizza média tem 6 pedaços → 6 * m

        Somamos tudo para saber o total necessário.
    */
    int total_necessario = (8 * g) + (6 * m);

    /*
        Se n (o que temos) for maior ou igual
        ao total necessário, então não falta nada.
    */
    if (n >= total_necessario) {

        cout << 0 << endl; // Nada falta

    } else {

        /*
            Caso contrário, faltam:

            total necessário - o que já temos
        */
        int faltam = total_necessario - n;
        cout << faltam << endl;
    }

    return 0; // Programa finalizado com sucesso
}