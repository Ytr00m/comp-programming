#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve() {
    int mod[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};

    ll n; cin >> n;
    ll res = n % 12;
    ll a = mod[res];
    if ( a > n) cout << -1 << "\n";
    else cout << a << " " << n - a << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) solve();

}
