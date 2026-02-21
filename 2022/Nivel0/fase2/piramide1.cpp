#include <iostream> // Biblioteca para entrada e saída (cin e cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe um número n
    e constrói uma "pirâmide" numérica dentro de uma matriz n x n.

    A ideia é a seguinte:

    - A camada mais externa da matriz recebe valor 1.
    - A próxima camada interna recebe +1 (fica 2).
    - A próxima recebe +1 (fica 3).
    - E assim por diante, até chegar ao centro.

    O resultado é uma matriz onde os números aumentam
    conforme nos aproximamos do centro.
*/

const int MAXN = 110;

// Matriz global (inicializada automaticamente com zeros)
int piramide[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;

    /*
        Vamos trabalhar por "níveis" (camadas).

        Exemplo para n = 5:

        nível 1 → cobre toda a matriz
        nível 2 → cobre a parte interna
        nível 3 → cobre apenas o centro

        O número total de níveis é (n + 1) / 2
    */
    for (int nivel = 1; nivel <= (n + 1) / 2; nivel++) {

        /*
            Para cada nível, percorremos apenas
            a área correspondente àquele "quadrado interno".

            Ele começa em:
                linha = nivel
                coluna = nivel

            E termina em:
                linha = n - nivel + 1
                coluna = n - nivel + 1
        */
        for (int i = nivel; i <= n - nivel + 1; i++) {
            for (int j = nivel; j <= n - nivel + 1; j++) {

                // Cada vez que passamos por um nível,
                // incrementamos aquela posição.
                piramide[i][j]++;
            }
        }
    }

    /*
        Agora imprimimos a matriz resultante.
    */
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            cout << piramide[i][j] << " ";
        }

        cout << endl;
    }

    return 0; // Programa finalizado corretamente
}