#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

const int MAXK = 20;
using namespace std;

ll dp[1 << MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    /*
    - Ler as habilidades de cada competidor
    - Somar 1 em cada subconjunto de habilidades encontrado
    */
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp = 0;
        for(int j = k-1; j >= 0; j--) {
            char c; cin >> c;
            if(c == '1'){
                tmp = tmp | (1 << j);
            }
        }
        dp[tmp]++;
    }
    /*
    - SOS DP para contar para cada subconjunto, qual a quantidade de competidores com algum subconjunto de habiliadedes
    */
    for(int i = 0; i < k; i++) {
        for(int mask = 0; mask < (1 << k); mask++) {
            if(mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
    /*
    - No resultado da SOS DP, calcular de quantas formas consigo fazer um time de 3 e salvar em F
    */
    for(int mask = 0; mask < (1 << k); mask++) {
        if (dp[mask] > 2){
            dp[mask] = (dp[mask] * (dp[mask]-1) * (dp[mask]-2)) / 6;
        } else {
            dp[mask] = 0;
        }
    }

    /*
    - Aplicar uma SOS DP reversa no passo anterior
    - Dessa forma, cada consulta ja estaa respondida de forma offline 
    */
    for(int i = 0; i < k; i++) {
        for(int mask = 0; mask < (1 << k); mask++) {
            if(mask & (1 << i)) {
                dp[mask] -= dp[mask ^ (1 << i)];
            }
        }
    }

   /*
   - Responder cada query apenas acessando o indice da mask
   */

    int q; cin >> q;
    tmp = 0;
    for(int i = 0; i < q; i++) {
        tmp = 0;
        for(int j = k-1; j >= 0; j--) {
            char c; cin >> c;
            if(c == '1'){
                tmp = tmp | (1 << j);
            }
        }
        cout << dp[tmp] << endl;
    }
}