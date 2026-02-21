#include <iostream>   // Biblioteca para entrada e saída (cin, cout)
using namespace std;

int main() {

    // n = tamanho da string
    int n;
    cin >> n;

    // s = string que será analisada
    // Como o limite é 1000, criamos um array um pouco maior
    char s[1010];
    cin >> s;

    // qtd = quantidade de caracteres repetidos consecutivos
    int qtd = 0;

    // last = guarda o último caractere analisado
    // Inicializamos com um valor qualquer que não será usado na string
    char last = '\0';

    // Percorremos a string caractere por caractere
    for (int i = 0; i < n; i++) {

        // Se for o primeiro caractere
        if (i == 0) {
            last = s[i];   // Define o primeiro caractere como o "último"
            qtd = 1;       // Começa contando 1 ocorrência
        }
        else if (s[i] == last) {
            // Se o caractere atual for igual ao anterior
            // Apenas aumentamos a contagem
            qtd++;
        }
        else {
            // Se for diferente, imprimimos o bloco anterior
            cout << " " << qtd << " " << last;

            // Reiniciamos a contagem para o novo caractere
            last = s[i];
            qtd = 1;
        }
    }

    // Depois que o laço termina, ainda precisamos imprimir o último grupo
    cout << " " << qtd << " " << last << endl;

    return 0; // Indica que o programa terminou corretamente
}