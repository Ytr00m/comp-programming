#include <iostream>

#define ll long long
using namespace std;

ll expb(ll a, ll b) {
    cout << a << " " << b << endl;
    if (b == 0) return 1;

    ll res = expb(a, b/2);
    cout << res << endl;
    if (b % 2 == 0){
        return res * res;
    } else{
        return res * res * a;
    }
}


int main() {
    ll n, m; cin >> n >> m;

    cout << expb(n, m) << endl;
}
