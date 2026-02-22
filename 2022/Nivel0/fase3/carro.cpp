/*
    ============================================================
    📌 EXPLICAÇÃO COMPLETA DO CÓDIGO
    ============================================================

    Este programa usa a estrutura UNION-FIND (Disjoint Set Union)
    para contar quantos grupos de pontos existem no plano.

    Dois pontos pertencem ao mesmo grupo se:

        100 * (|x1 - x2| + |y1 - y2|) <= d

    Ou seja:
    A distância de Manhattan entre eles,
    multiplicada por 100,
    deve ser menor ou igual a d.
*/

#include <iostream>     // Entrada e saída (cin, cout)
#include <algorithm>    // Funções como max(), min()
#include <vector>       // Estrutura dinâmica de vetor (não usada aqui)
#include <utility>      // pair<int,int> (não usada aqui)
#include <cmath>        // abs()
#include <cstdio>       // scanf e printf

/*
    🔎 OBSERVAÇÃO SOBRE AS BIBLIOTECAS

    Algumas dessas bibliotecas NÃO são usadas diretamente
    neste código.

    Isso é comum em competições (OBI, ICPC, etc),
    onde o programador já deixa um "template pronto"
    com várias bibliotecas incluídas para usar se precisar.

    Aqui, realmente necessárias são:
        - <cstdio>  → scanf / printf
        - <cmath>   → abs()
*/

using namespace std;

/*
    🔎 Defines (atalhos usados em competição)

    São apelidos criados para facilitar digitação.
*/

#define ll long long           // Tipo inteiro 64 bits
#define pb push_back           // Atalho para vector.push_back()
#define pii pair<int,int>      // Atalho para pair<int,int>
#define maxn 400400            // Tamanho máximo dos vetores
#define mod 1000000007         // Muito usado em problemas com módulo

/*
    ⚠ IMPORTANTE:
    Neste código específico, vários desses defines
    NÃO são utilizados.
    Eles fazem parte de um template padrão.
*/

int n, d;              // n = quantidade de pontos | d = limite da distância
int x[maxn];           // Coordenadas x dos pontos
int y[maxn];           // Coordenadas y dos pontos
int p[maxn];           // Vetor de pais (Union-Find)

/*
    ============================================================
    🔹 UNION-FIND (Disjoint Set Union)
    ============================================================

    Ideia:
    - Cada elemento começa sendo seu próprio grupo.
    - Quando dois devem ficar conectados, unimos os grupos.
    - O vetor p[] guarda o "pai" de cada elemento.
*/

/*
    🔹 Função find(x)

    Objetivo:
    Encontrar o representante (raiz) do conjunto de x.

    Se p[x] == x → ele é a raiz.
    Caso contrário → subimos até encontrar a raiz.

    Também usamos "compressão de caminho":
    depois de encontrar a raiz,
    fazemos p[x] apontar diretamente para ela.
    Isso deixa futuras buscas mais rápidas.
*/
int find(int x){
    return p[x] = (x == p[x]) ? x : find(p[x]);
}

int main(){

    /*
        Lê 4 números da entrada,
        mas ignora os dois primeiros.

        %*d → lê mas descarta o valor.
    */
    scanf("%*d%*d%d%d", &n, &d);

    /*
        Leitura dos pontos.

        Inicialmente:
        Cada ponto é seu próprio grupo.
        Então p[i] = i.
    */
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
        p[i] = i; // cada ponto começa isolado
    }

    /*
        Agora comparamos TODOS os pares de pontos.

        Para cada par (i, j):
        - Calculamos a distância de Manhattan:
              |x[i] - x[j]| + |y[i] - y[j]|

        - Multiplicamos por 100
        - Se for <= d → unimos os grupos.
    */
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);

            if(100 * dist <= d){

                /*
                    Unindo os conjuntos:

                    find(i) → raiz do grupo de i
                    find(j) → raiz do grupo de j

                    Tornamos a raiz de i filha da raiz de j.
                */
                p[find(i)] = find(j);
            }
        }
    }

    /*
        Agora precisamos contar
        quantos grupos existem.

        Em Union-Find:
        Cada grupo é representado por uma raiz.
        Uma raiz é um índice i tal que p[i] == i.
    */

    int ans = -1;

    for(int i = 0; i < n; i++){
        if(p[i] == i)
            ans++;
    }

    /*
        🔎 Por que começa em -1?

        Porque normalmente o problema quer:

            número de grupos - 1

        Isso é comum quando:
        - Queremos saber quantas conexões faltam
        - Ou quantas operações para ligar tudo

        Se existirem:
            1 grupo → resposta = 0
            2 grupos → resposta = 1
            3 grupos → resposta = 2
    */

    printf("%d\n", ans);

    return 0;
}