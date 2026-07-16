#include <bits/stdc++.h>
using ll = long long;

const ll MOD = 1e9+7;
using namespace std;

ll expb(ll a, ll b){
    if(b == 0) return 1LL;
    ll res = expb(a, b/2);
    if(b % 2 == 0) {
        return (res * res) % MOD;
    } else {
        return (((res * res) % MOD) * a) % MOD;
    }
}

int main() {
    ll a, b; cin >> a >> b;

    ll pa = expb(2, a);
    ll pb = expb(2, b);
    ll pm = expb(2, min(a, b));
    pm = expb(pm, MOD-2);

    ll res = (((((pa * pb) % MOD) * 2) % MOD) * pm) % MOD;

    cout << res << endl;
}