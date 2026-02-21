#include <iostream>   // Biblioteca para entrada e saída (cin, cout)
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Este programa faz uma "compressão" simples da string.

    Ele recebe:
    - n → tamanho da string
    - s → a string

    O que ele faz?
    Agrupa letras iguais consecutivas e imprime:

        quantidade letra

    Exemplo:
    Entrada:  AAAABBCC
    Saída:    4 A 2 B 2 C

    Ou seja, ele conta blocos consecutivos de caracteres iguais.
*/

int main() {

    // n = tamanho da string
    int n;
    cin >> n;

    // s = string que será analisada
    // Criamos um vetor de char grande o suficiente
    char s[1010];
    cin >> s;

    // qtd = conta quantas vezes o mesmo caractere aparece seguido
    int qtd = 0;

    // last = guarda o caractere anterior
    char last = '\0'; // inicializamos com vazio

    /*
        Percorremos a string inteira
        analisando caractere por caractere.
    */
    for (int i = 0; i < n; i++) {

        // Caso especial: primeiro caractere
        if (i == 0) {
            last = s[i];  // definimos o primeiro caractere como referência
            qtd = 1;      // começamos contando 1 ocorrência
        }

        // Se for igual ao anterior → continua o bloco
        else if (s[i] == last) {
            qtd++;        // aumenta a contagem
        }

        // Se for diferente → o bloco terminou
        else {

            /*
                Aqui sabemos que terminou um grupo
                de caracteres iguais.

                Então imprimimos:
                quantidade + caractere
            */
            cout << qtd << " " << last << " ";

            // Começamos um novo bloco
            last = s[i];
            qtd = 1;
        }
    }

    /*
        Quando o laço termina,
        ainda falta imprimir o último bloco,
        pois ele não entra no else.
    */
    cout << qtd << " " << last << endl;

    return 0; // Programa finalizado com sucesso
}