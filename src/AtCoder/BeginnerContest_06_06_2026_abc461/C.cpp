#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pli pair<ll, int>

int const MAXN = 2e5 + 2;

using namespace std;

bool seen[MAXN];
vector<pli> gems;

int main() {
    int n, m, k; cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        pli tmp; cin >> tmp.s >> tmp.f;
        gems.push_back(tmp);
    }
    ll ans = 0;
    int types = 0;
    int qtd = 0;
    sort(gems.rbegin(), gems.rend());

    for( auto [value, i] : gems) {
        if (seen[i] == false && qtd < m) {
            seen[i] = true;
            types++;
            qtd++;
            ans += value;
            //cout << "Pegou " << value << " : qtd " << qtd << " : types " << types << endl;
        }else if( qtd < m && seen[i] == true && m - qtd > k - types ) {
            qtd++;
            ans +=value;

            //cout << "Pegou " << value << " : qtd " << qtd << " : types " << types << endl;
        }
    }
 

    cout << ans << endl;
}
