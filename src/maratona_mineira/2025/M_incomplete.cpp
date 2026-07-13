// Link para o problema: https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/M

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100003
#define ll long long
#define pil pair<int, ll>
#define plii pair<ll, pil>
#define mp make_pair
#define INF 10000000000000001


vector<int> g[MAXN];
ll dist[MAXN], alt[MAXN];

priority_queue<plii, vector<plii>, greater<>> hp;
int N, M, H;

/*
    Cada vertice tem uma altitude.
    Só posso ir para algum vértice desde que ele possua uma altitude dentro do range
    [hi, hi+H], sendo hi a altitude da última cidade em que eu dormi, e começa com 0.
    Se eu não conseguir ir para alguma cidade, eu posso verificar se eu conseguiria ir para ela
    se eu dormir na cidade atual, se sim, adiciono +1 na minha "distancia", sinalizando que dormi +1 dia,
    e atualizo meu hi para esse vertice me questão.

    No final, a distância para o vértice N é minha resposta.
    A estrutura que guardarei na fila vai ser:
    (qtd_dias, (vertice, hi)) -> sendo hi a altitude da ultima cidade que dormi, naquele "tour".
    e também: hi <= alt[vertice] <= hi + H (exceto)
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> H;

    for( int i = 1; i < MAXN; i++){
            dist[i] = INF;
    }

    for(int i = 1; i <= N; i++){
        cin >> alt[i];
    }

    int ai, bi; 
    for(int i = 0; i < M; i++){
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }

    dist[1] = 1;
    hp.push(mp(1, mp(1, 0)));

    while(!hp.empty()) {
        auto [qtd_dias , node_info] = hp.top();
        auto [v, hi] = node_info;

        hp.pop();

        if (dist[v] < qtd_dias) continue;

        for(auto u : g[v]) {

            if (hi <= alt[u] && alt[u] <= hi + H) {
                dist[u] = qtd_dias;
                hp.push(mp(dist[u], mp(u, hi)));
                cout << "Indo de [" << v << "] para [" << u << "] sem dormir com [" << dist[u] << "] dias" << endl;  
            } else if (alt[v] <= alt[u] && alt[u] <= alt[v] + H){

                dist[u] = qtd_dias + 1;
                cout << "Indo de [" << v << "] para [" << u << "] dormindo no atual [" << alt[v] << "] com [" << dist[u] << "] dias" << endl;  
                hp.push(mp(dist[u], mp(u, alt[v])));
            }
            
            // cout << "Estado atual [" << cur_state << "], Tipo da aresta [" << edge_type << "]" << ", Prox Estado [" << next_state << "]" << endl;
        }
    }

    cout << dist[N] << endl;
    // cout << dist[N][0] << " " << dist[N][1] << " " << dist[N][2] << endl;
    
}
