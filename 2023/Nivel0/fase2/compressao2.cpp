#include <iostream>  // Biblioteca para entrada e saída (cin, cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Este programa faz uma compressão simples de uma string.

    Ele recebe:
    - n → tamanho da string
    - codigo → a string

    O que ele faz?
    Conta quantas vezes cada caractere aparece consecutivamente
    e imprime no formato:

        quantidade letra

    Exemplo:
    Entrada:  AAABBCCCC
    Saída:    3 A 2 B 4 C

    Ou seja, ele agrupa blocos de letras iguais consecutivas.
*/

// Array global para armazenar a string
// Tamanho 1100 para garantir segurança
char codigo[1100];

int main() {

    // n = quantidade de caracteres da string
    int n;
    cin >> n;

    // Lê a string
    cin >> codigo;

    // contador = quantidade de repetições consecutivas
    int contador = 0;

    // letra_anterior = guarda a última letra analisada
    char letra_anterior = '\0'; // inicia vazio

    /*
        Percorremos todos os caracteres da string.
        A ideia é detectar quando a letra muda,
        pois isso indica que um bloco terminou.
    */
    for (int i = 0; i < n; i++) {

        char letra_atual = codigo[i];

        /*
            Se a letra atual for diferente da anterior,
            significa que começou um novo bloco.
        */
        if (letra_atual != letra_anterior) {

            /*
                Se contador > 0,
                significa que já existia um bloco anterior.
                Então precisamos imprimir ele antes de começar o novo.
            */
            if (contador > 0) {
                cout << contador << " " << letra_anterior << " ";
            }

            // Atualizamos para começar o novo bloco
            letra_anterior = letra_atual;
            contador = 1;
        }
        else {
            // Se for igual, continuamos contando
            contador++;
        }
    }

    /*
        Quando o laço termina,
        ainda falta imprimir o último bloco,
        pois ele não entra novamente no if.
    */
    cout << contador << " " << letra_anterior << endl;

    return 0; // Programa finalizado com sucesso
}