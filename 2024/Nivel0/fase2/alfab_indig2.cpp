#include <iostream>   // Para usar cin e cout
#include <string>     // Para usar string
#include <set>        // Para usar a estrutura set
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe:
    - k → tamanho do alfabeto permitido
    - n → tamanho da mensagem
    - alphabet → string com os caracteres permitidos
    - message → mensagem que queremos validar

    Ele verifica se TODOS os caracteres da mensagem
    pertencem ao alfabeto permitido.

    🔹 Diferença desta versão:
    Usamos um "set" para armazenar as letras do alfabeto.
    Isso permite verificar rapidamente se uma letra existe ou não.

    Se encontrar algum caractere inválido → imprime "N" e encerra.
    Se todos forem válidos → imprime "S".
*/

int main() {

    int k, n;
    string alphabet, message;

    // Lê tamanho do alfabeto e da mensagem
    cin >> k >> n;

    // Lê a string do alfabeto
    cin >> alphabet;

    /*
        Criamos um set contendo todas as letras do alfabeto.

        set<char> é uma estrutura que:
        - Não permite repetição
        - Permite verificar rapidamente se um elemento existe
    */
    set<char> alphabet_set(alphabet.begin(), alphabet.end());

    // Lê a mensagem
    cin >> message;

    /*
        Percorremos cada caractere da mensagem.
        Se algum caractere NÃO estiver no set,
        já sabemos que a mensagem é inválida.
    */
    for (char c : message) {

        // count(c) retorna:
        // 1 → se o caractere existe no set
        // 0 → se não existe
        if (!alphabet_set.count(c)) {

            // Encontramos caractere inválido
            cout << "N" << endl;

            // Encerramos o programa imediatamente
            return 0;
        }
    }

    // Se chegamos aqui, todos os caracteres são válidos
    cout << "S" << endl;

    return 0; // Finaliza o programa corretamente
}