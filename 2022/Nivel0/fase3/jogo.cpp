#include <bits/stdc++.h> // Inclui praticamente todas as bibliotecas padrão
using namespace std;

/*
    📌 OBI 2022 – Fase 3
    🎮 Tarefa: Jogo

    💡 O que o programa faz?

    - Lê um número secreto x.
    - Depois entra em um loop infinito.
    - A cada rodada, lê um palpite t.
    - Compara t com x:
        • Se t for maior que x → imprime "menor"
        • Se t for menor que x → imprime "maior"
        • Se t for igual a x   → imprime "correto" e encerra

    Isso simula um jogo de adivinhação.
*/

int main() {

    int x; // Número secreto
    int t; // Palpite

    scanf("%d", &x); // Lê o número correto

    while (true) { // Loop infinito até acertar

        scanf("%d", &t); // Lê o palpite

        if (t > x) {
            // O palpite é maior que o número secreto
            printf("menor\n"); // Dica: o número correto é menor
        }
        else if (t < x) {
            // O palpite é menor que o número secreto
            printf("maior\n"); // Dica: o número correto é maior
        }
        else {
            // Acertou!
            printf("correto\n");
            break; // Sai do loop
        }
    }

    return 0; // Finaliza o programa
}