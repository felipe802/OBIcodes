#include <iostream>  // Biblioteca para usar cin e cout
using namespace std;

// Array para armazenar o código (string de caracteres)
// Tamanho 1100 para garantir espaço suficiente
char codigo[1100];

int main() {

    // n = quantidade de caracteres da string
    int n;
    cin >> n;

    // Lê a string (sequência de letras)
    cin >> codigo;

    // contador = conta quantas vezes a mesma letra aparece seguida
    int contador = 0;

    // letra_anterior = guarda a última letra analisada
    // Inicializamos com um valor qualquer diferente das letras válidas
    char letra_anterior = '\0';

    // Percorre todos os caracteres da string
    for (int i = 0; i < n; i++) {

        // Guarda a letra atual
        char letra_atual = codigo[i];

        // Se a letra atual for diferente da anterior,
        // significa que terminou um "bloco" de letras repetidas
        if (letra_atual != letra_anterior) {

            // Se o contador for maior que 0,
            // significa que já temos um bloco anterior para imprimir
            if (contador > 0) {
                cout << contador << " " << letra_anterior << " ";
            }

            // Atualiza a letra anterior para a atual
            letra_anterior = letra_atual;

            // Reinicia o contador (começa novo bloco)
            contador = 1;
        }
        else {
            // Se a letra for igual à anterior,
            // apenas aumenta a contagem
            contador++;
        }
    }

    // Após o laço terminar, ainda falta imprimir o último bloco
    cout << contador << " " << letra_anterior << endl;

    return 0; // Indica que o programa terminou corretamente
}