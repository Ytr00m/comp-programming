#include <bits/stdc++.h>

const int MAXN = 2e5 + 5;
const int LG_MAXN = 18;

#define ll long long
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll st[LG_MAXN][MAXN]; // Sparse Table
ll arr[MAXN];

ll query(int a, int b){
    /*
        Devo tirar o minimo entre o intervalo a e b. Como tenho somente o minimo de intervalos]
        com tamanho de pot√ncias de 2, posso selecinar dois subintervalos e tirar o minimo entre eles
        desde que a uniao dos dois seja o intervalo a e b.

        (a, a+x) e (a+x+1, b)
        (b-a-x-1) = x
        b-a = 2x
        b-a-1 = 2x
        x = (b-a-1)/2

        precisamos encontrar que x seria esse, ent√o.
        Olhando so para o subintervalo (a, a+x),
        lembramos que:
        st[i][j] = min no range (j, j+2^i - 1)
        logo se j = a
        x = 2^i - 1
        isolando o i:
        2^i = x + 1
        i = log(x + 1)
        
        logo, o range (a, a+x) equivale ao que esta em st[log(x+1)][a]
        
        entao, o range (a+x+1, b) equivale 
        (a+x+1, a+x+1 + 2^i - 1)
        ent√o b = a+x+1 + 2^i - 1
        logo:
        2^i = b-a-x
        2^i = b-a + (a+1-b)/2
        2^i = (2b-2a+a+1-b)/2
        2^i = (b-a+1)/2
        i = log(b-a+1) - 1

        Seja b-a+1 = L o tamanho do intervalo

        x+1 = (b-a+1)/2
        x = L/2

        ou seja
        para (a, a+x)
        i = log(L + 2) - 1
        
        para (a+x+1, b)
        i = log(L) - 1

        Como podemos muito bem pegar dois intervalos que se sobrep√em, mas que juntos cobrem o intervalo todo,
        e nosso m√nimo n√o mudar√, precisamos garantir somente que o tamanho dos dois seja <= L
        ou seja:
        x <= L
        log(x) <= log(L)
    */
    int k = __lg(b-a+1);

    return min(st[k][a], st[k][b - (1 << k) + 1]);
}

int main () {
    fast_io();

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Construindo a Sparse Table usando DP
    // st[i][j] = soma entre (j, j+2^i - 1) ex i = 2 j = 3, st[2][3] = soma entre (3, 3+2^2 - 1) = (3, 6), ou seja, tamanho 2^2
    // Posso divir o range (j, j+2^i - 1), de tamanho 2^i, em dois ranges de tamanho 2^(i-1)
    // que corresponde aos ranges (j, j+2^(i-1) - 1) e (j+2^(i-1), j+2^i - 1)
    // e eh representado, na st, por st[i-1][j] e st[i-1][j+2^(i-1)]
    // Ou seja:
    // st[i][j] = arr[j] para i = 0
    // st[i][j] = min(st[i-1][j], st[i-1][j+2^(i-1)]) para i > 0 e j < N - 2^i - 1

    for(int j = 1; j <= n; j++) st[0][j] = arr[j];

    for(int i = 1; i < LG_MAXN; i++) {
        for(int j = 1; j <= n - (1 << i) + 1; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
        }
    }
    int a, b;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    /*
    int lg_n = __lg(n);
    for(int i = 0; i <= lg_n; i++) {
       cout << "Tamanho " << (1 << i) << " => ";
       for(int j = 1; j <= n - (1 << i) + 1; j++) {
           cout << st[i][j] << " ";
       }
       cout << endl;
    }
    */
}
