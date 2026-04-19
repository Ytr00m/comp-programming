#include <bits/stdc++.h>

const int MAXN = 2e5 + 5;
#define ll long long
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll parr[MAXN];

ll query(int a, int b){
    return parr[b] - parr[a-1];
}

int main () {
    fast_io();

    int n, q; cin >> n >> q;

    ll tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        parr[i] = parr[i-1] + tmp;
    }

    int a, b;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }



}
