#include <bits/stdc++.h> // Biblioteca que inclui praticamente tudo da STL
using namespace std;

/*
    📌 O que este programa faz?

    Ele imprime uma matriz n x n formando uma "pirâmide"
    (ou matriz em camadas), onde:

    - As bordas têm valor 1
    - A próxima camada interna tem valor 2
    - E assim por diante, até o centro

    💡 DIFERENÇA IMPORTANTE:
    Aqui não usamos matriz auxiliar nem vários loops por nível.
    Calculamos diretamente o valor de cada posição usando matemática.
*/

int main() {

    int n;
    scanf("%d", &n);

    /*
        Vamos percorrer cada posição (i, j) da matriz.

        A ideia é descobrir:
        "Qual é a distância dessa posição até a borda mais próxima?"

        Porque essa distância determina o valor da célula.
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            // Distância até a borda de cima
            int cima = i;

            // Distância até a borda de baixo
            int baixo = n + 1 - i;

            // Distância até a borda esquerda
            int esq = j;

            // Distância até a borda direita
            int dir = n + 1 - j;

            /*
                O valor da célula será a MENOR dessas distâncias,
                pois isso indica qual camada ela pertence.
            */
            int valor = min(min(cima, baixo), min(esq, dir));

            printf("%d ", valor);
        }

        printf("\n");
    }

    return 0; // Finaliza corretamente
}