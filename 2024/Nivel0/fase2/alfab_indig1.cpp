#include <iostream>   // Para usar cin e cout
#include <string>     // Para usar string
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe:
    - k → tamanho do alfabeto permitido
    - n → tamanho da mensagem
    - alphabet → string com as letras permitidas
    - message → mensagem que queremos verificar

    O objetivo é verificar se TODOS os caracteres da mensagem
    pertencem ao alfabeto permitido.

    Se todos os caracteres forem válidos → imprime "S"
    Se existir pelo menos um caractere inválido → imprime "N"
*/

int main() {

    // k = tamanho do alfabeto
    // n = tamanho da mensagem
    int k, n;

    // alphabet = letras permitidas
    // message = mensagem a ser analisada
    string alphabet, message;

    cin >> k >> n;
    cin >> alphabet;
    cin >> message;

    // Variável que indica se a mensagem é válida
    // Começamos assumindo que ela é válida
    bool good_message = true;

    /*
        Percorremos cada caractere da mensagem.
        Para cada caractere, precisamos verificar
        se ele existe dentro do alfabeto permitido.
    */
    for (char c : message) {

        // Variável que indica se encontramos o caractere no alfabeto
        bool found_char = false;

        // Procuramos o caractere atual dentro do alphabet
        for (char d : alphabet) {
            if (c == d) {
                found_char = true;  // Encontramos!
            }
        }

        // Se não encontramos o caractere no alfabeto,
        // então a mensagem é inválida
        if (!found_char) {
            good_message = false;
        }
    }

    // Se a mensagem for válida, imprime "S"
    // Caso contrário, imprime "N"
    if (good_message)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0; // Finaliza o programa corretamente
}