#include <iostream>   // cin, cout
#include <cstring>    // funções de manipulação (não é essencial aqui)
#include <cassert>    // assert()
#include <algorithm>  // funções auxiliares (não é essencial aqui)
using namespace std;

/*
    ============================================================
    📌 IDEIA GERAL DO PROGRAMA
    ============================================================

    Dado um número grande X (lido como string),
    queremos descobrir qual é o PRIMEIRO número A
    tal que X é formado por:

        A, A+1, A+2, A+3, ...

    concatenados.

    Exemplo:
        X = "91011"
        A = "9"
        sequência: 9, 10, 11
        → funciona

        X = "99100"
        A = "99"
        sequência: 99, 100
        → funciona

    Como X pode ser muito grande,
    usamos string em vez de int.
*/

/*
    ============================================================
    🔹 Função add1
    ============================================================

    Recebe um número grande como string
    e retorna esse número + 1.

    Exemplo:
        "9"   → "10"
        "19"  → "20"
        "999" → "1000"

    Fazemos manualmente porque pode ser
    maior que long long.
*/
string add1(string s){
    string res = s;  // copiamos a string
    int carry = 1;   // queremos somar 1

    // Percorremos da direita para esquerda
    for(int i = int(res.size()) - 1; i >= 0; i--){
        int nv = (res[i] - '0') + carry;
        carry = 0;

        if(nv >= 10){
            carry = 1;
            nv -= 10;
        }

        res[i] = char('0' + nv);
    }

    // Se sobrou carry (ex: 999 → 1000)
    if(carry)
        res = "1" + res;

    return res;
}

int main(){

    /*
        🔹 Otimização de entrada/saída
        Deixa cin/cout mais rápidos.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X;   // número completo
    int d;      // quantidade de dígitos

    cin >> d;
    assert(d > 0);  // garante que d > 0

    /*
        Lemos os dígitos um por um
        e montamos a string X.
    */
    while(d--){
        char c;
        cin >> c;
        X += c;
    }

    // Não pode começar com zero
    assert(X[0] != '0');

    /*
        ========================================================
        🔹 Tentamos todos os possíveis tamanhos para o primeiro número
        ========================================================

        Se X tem tamanho N,
        o primeiro número pode ter tamanho 1 até N.
    */
    for(int t = 1; t <= X.size(); t++){

        // Pegamos os primeiros t dígitos
        string A = X.substr(0, t);

        int curPos = 0;   // posição atual dentro de X
        int ok = 1;       // flag para saber se deu certo
        string num = A;   // número atual esperado

        /*
            Agora tentamos reconstruir X:

            Enquanto não chegarmos ao final:
                - Verificamos se o próximo pedaço bate com num
                - Depois fazemos num = num + 1
        */
        while(curPos < X.size()){

            // Se passar do tamanho de X → falha
            if(curPos + num.size() - 1 >= X.size()){
                ok = 0;
                break;
            }

            // Conferimos caractere por caractere
            for(int i = curPos; i < curPos + num.size(); i++){
                if(X[i] != num[i - curPos]){
                    ok = 0;
                    break;
                }
            }

            if(!ok)
                break;

            // Avança a posição
            curPos += num.size();

            // Próximo número da sequência
            num = add1(num);
        }

        /*
            Se conseguimos consumir toda a string
            sem erro, achamos o A correto.
        */
        if(ok){
            cout << A << "\n";
            return 0;
        }
    }
}