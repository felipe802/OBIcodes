#include <iostream>   // Para usar cin e cout
#include <algorithm>  // Para usar max() e min()
using namespace std;

/*
    📌 RESUMO DO PROGRAMA:

    Temos um caminho circular com n posições.
    Cada posição tem um valor p[i].

    O objetivo é encontrar o maior número de pares consecutivos
    cuja soma seja MENOR que 1000.

    Como o caminho é circular, o último elemento liga com o primeiro.
    Para facilitar isso, duplicamos o vetor:
        p[i + n] = p[i]

    Depois percorremos esse vetor estendido
    contando quantas vezes seguidas a soma de vizinhos é < 1000.

    No final:
    - Pegamos o maior bloco consecutivo encontrado.
    - Limitamos o resultado a no máximo n.
*/

// Tamanho máximo (problema permite até 500000)
const int MAXN = 500010;

// Vetor com o dobro do tamanho para simular circularidade
int p[2 * MAXN];

int main() {

    int n;
    cin >> n;

    // ================================
    // 🔹 Leitura dos valores originais
    // ================================
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // ================================
    // 🔹 Duplicação do vetor
    // ================================
    /*
        Para simular o comportamento circular,
        copiamos o início do vetor para o final.
    */
    for (int i = n + 1; i <= 2 * n; i++) {
        p[i] = p[i - n];
    }

    // ================================
    // 🔹 Busca do maior trecho válido
    // ================================

    int resp = 0; // maior sequência encontrada
    int cur = 0;  // sequência atual

    /*
        Percorremos verificando pares consecutivos:
        (p[i-1], p[i])

        Se a soma for < 1000 → continuamos a sequência.
        Caso contrário → zeramos o contador.
    */
    for (int i = 2; i <= 2 * n; i++) {

        if (p[i] + p[i - 1] < 1000) {
            cur++;              // continua sequência
        } else {
            cur = 0;            // quebra sequência
        }

        resp = max(resp, cur);  // atualiza melhor resposta
    }

    /*
        Como duplicamos o vetor,
        garantimos que a resposta não ultrapasse n.
    */
    resp = min(resp, n);

    cout << resp << endl;

    return 0; // Programa finalizado corretamente
}