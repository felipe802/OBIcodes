#include <bits/stdc++.h>
using namespace std;

/*
    📌 OBI 2022 – Tarefa: Teste de Redação

    💡 O que o programa faz?

    - Lê dois inteiros: n e m.
    - Para cada número i de 1 até m:
        • Pega seus dígitos (base 10)
        • Para cada dígito, imprime uma letra correspondente

    🔎 Como funciona o mapeamento?

    Temos a string:
        "abcdefghijklmnopqrstuvwxyz"

    Cada posição representa:
        0 → 'a'
        1 → 'b'
        2 → 'c'
        ...
        9 → 'j'

    Ou seja:
        dígito 0 imprime 'a'
        dígito 1 imprime 'b'
        ...
        dígito 9 imprime 'j'

    Ele percorre os dígitos de trás para frente
    (porque usa x % 10 e depois x /= 10).
*/

int n, m;
string letras = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
  
    scanf("%d%d", &n, &m);

    // Para cada número de 1 até m
    for (int i = 1; i <= m; i++) {

        int x = i;

        // Enquanto ainda houver dígitos
        while (x > 0) {

            // x % 10 pega o último dígito
            // letras[x % 10] pega a letra correspondente
            printf("%c", letras[x % 10]);

            x /= 10; // remove o último dígito

            printf(" "); // espaço após cada letra
        }
    }

    printf("\n");

    return 0;
}