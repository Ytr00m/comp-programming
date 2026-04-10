// Link: https://codeforces.com/gym/106073/problem/E
#include <bits/stdc++.h>
using namespace std;

int const MAXN = 1e5 + 1;

vector<int> adj[MAXN];
int ant[MAXN];
int grau[MAXN];
bool seen[MAXN];

void dfs(int p, int v){

    // ant[v] = p;
    if (p != v){
        cout << p << " " << v << endl;
    }
    seen[v] = true;
    for( auto i : adj[v]) {
        if (!seen[i]){
            dfs(v, i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        grau[a]++;
        grau[b]++;
    }

    if (M == N-1) {
        cout << "*" << endl;
        return 0;
    }

    int qtd_2, qtd_3, qtd_4;
    qtd_2 = qtd_3 = qtd_4 = 0;

    for(int i = 1; i <= N; i++) {
        if(grau[i] == 2) qtd_2++;
        if(grau[i] == 3) qtd_3++;
        if(grau[i] == 4) qtd_4++;
    } 
    
    // cout << qtd_2 << " " << qtd_3 << " " << qtd_4 << endl;
    if (qtd_2 + qtd_3 + qtd_4 < N){
        cout << "*" << endl;
        return 0;
    }

    dfs(1, 1);
}