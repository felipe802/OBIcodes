#include <iostream> // Para usar cin e cout
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    O programa recebe 5 números inteiros.

    Ele faz duas coisas:
    1) Descobre qual é o MAIOR valor.
    2) Conta quantas vezes esse maior valor aparece.
    3) Descobre qual é o SEGUNDO valor diferente do maior.
    4) Conta quantas vezes esse segundo valor aparece.

    No final, imprime:
        quantidade_do_maior  quantidade_do_segundo
*/

int main() {

    // Leitura dos 5 valores
    int n1, n2, n3, n4, n5;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    // ================================
    // 🔹 Descobrindo o maior valor
    // ================================

    /*
        Como o código original assume que n1 é o maior,
        vamos manter essa mesma lógica.
    */
    int maior = n1;

    /*
        Agora vamos encontrar um valor diferente do maior
        para servir como candidato a segundo valor.
    */
    int maior2 = -1;

    if (n2 != maior)
        maior2 = n2;
    else if (n3 != maior)
        maior2 = n3;
    else if (n4 != maior)
        maior2 = n4;
    else if (n5 != maior)
        maior2 = n5;

    // ================================
    // 🔹 Contando quantas vezes o maior aparece
    // ================================

    /*
        Começamos com 1 porque já consideramos n1 como maior.
    */
    int t = 1;

    if (n2 == maior) t++;
    if (n3 == maior) t++;
    if (n4 == maior) t++;
    if (n5 == maior) t++;

    // ================================
    // 🔹 Contando quantas vezes o segundo valor aparece
    // ================================

    int p = 0;

    if (n2 == maior2) p++;
    if (n3 == maior2) p++;
    if (n4 == maior2) p++;
    if (n5 == maior2) p++;

    // ================================
    // 🔹 Saída
    // ================================

    cout << t << " " << p << endl;

    return 0; // Programa finalizado corretamente
}