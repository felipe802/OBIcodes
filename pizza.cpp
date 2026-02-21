#include <iostream> // Biblioteca para usar cin e cout
using namespace std;

int main() {

    // Variáveis:
    // n = quantidade atual de pedaços
    // g = quantidade de pizzas grandes (8 pedaços cada)
    // m = quantidade de pizzas médias (6 pedaços cada)
    int n, g, m;

    // Lendo os valores digitados pelo usuário
    cin >> n >> g >> m;

    // Calculando o total de pedaços necessários
    // Cada pizza grande tem 8 pedaços
    // Cada pizza média tem 6 pedaços
    int total_necessario = (8 * g) + (6 * m);

    // Se já temos pedaços suficientes
    if (n >= total_necessario) {
        // Não falta nenhum pedaço
        cout << 0 << endl;
    } 
    else {
        // Calculamos quantos pedaços estão faltando
        int faltam = total_necessario - n;
        cout << faltam << endl;
    }

    return 0; // Indica que o programa terminou corretamente
}