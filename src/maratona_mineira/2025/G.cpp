// Link para o problema: https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/G

#include <bits/stdc++.h>
using namespace std;

#define MAXN 500001
#define ll long long
#define pii pair<int, int>
#define plii pair<ll, pii>
#define mp make_pair
#define INF 10000000000000001

#define INVALID_STATE -1

vector<plii> g[MAXN];
ll dist[MAXN][3];

priority_queue<plii, vector<plii>, greater<>> hp;
int N, C, P;

int getNextState(int cur_state, int edge_type){
    int n_state = INVALID_STATE;
    if (cur_state == 0 && edge_type == 0){
        n_state = 0;
    } else if (cur_state == 0 && edge_type == 1) {
        n_state = 1;
    } else if (cur_state == 1 && edge_type == 0) {
        n_state = 2;
    } else if (cur_state == 1 && edge_type == 1) {
        n_state = 1;
    } else if (cur_state == 2 && edge_type == 0) {
        n_state = 2;
    } else if (cur_state == 1 && edge_type == 0) {
        n_state = INVALID_STATE;
    }

    return n_state;
}

/*
    Tipos de Arestas:
        0 -> a pe ( mao dupla )
        1 -> carro ( mao unica )
    Estados:
        0 -> Usei por enquanto so arestas do tipo 0 ( a pe )
        1 -> Usei primeiro arestas do tipo 0 e agora comecei a usar arestas do tipo 1 ( carro )
        2 -> Usei primeiros do tipo 0, depois do tipo 1 e agora voltei a usar do tipo 0 novamente
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C >> P;

    for( int i = 1; i < MAXN; i++){
        for( int j = 0; j < 3; j++) {
            dist[i][j] = INF;
        }
    }
    ll ci;
    int ai, bi;
    for(int i = 0; i < C; i++){
        cin >> ai >> bi >> ci;
        g[ai].push_back(mp(ci, mp(bi, 1)));
    }

    for(int i = 0; i < P; i++){
        cin >> ai >> bi >> ci;
        g[ai].push_back(mp(ci, mp(bi, 0)));
        g[bi].push_back(mp(ci, mp(ai, 0)));
    }

    dist[1][0] = 0;
    hp.push(mp(0, mp(1, 0)));

    while(!hp.empty()) {
        auto [peso_v , node_info] = hp.top();
        auto [v, cur_state] = node_info;

        hp.pop();

        if (dist[v][cur_state] < peso_v) continue;

        for(auto [p, node_info] : g[v]) {
            auto [dest, edge_type] = node_info;
            int next_state = getNextState(cur_state, edge_type);
            
            // cout << "Estado atual [" << cur_state << "], Tipo da aresta [" << edge_type << "]" << ", Prox Estado [" << next_state << "]" << endl;
            if (next_state == INVALID_STATE) continue;
            if (dist[dest][next_state] > peso_v + p) {
                // cout << "Indo de [" << v << "] para [" << dest << "] usando aresta [" << edge_type << "]" << endl;  
                dist[dest][next_state] = peso_v + p;

                hp.push(mp(dist[dest][next_state], mp(dest, next_state)));
            }
        }
    }

    cout << min({dist[N][0], dist[N][1], dist[N][2]}) << endl;
    // cout << dist[N][0] << " " << dist[N][1] << " " << dist[N][2] << endl;
    
}
