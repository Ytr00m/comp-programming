#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;


void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    vector<ll> target(n);
    ll sum = 0;
    for(int j = 0; j < n; j++) {
        ll i; cin >> i;
        arr[j] = i;
        sum += i;
    }

    ll s = 0;
    for(ll i = 1; i < n; i++){
        target[i-1] = i;
        s += i;
        sum -= i;
    }
    
    if(sum < n) {
        cout << "NO" << endl;
        return;
    }

    target[n-1] = sum;

    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(arr[i] != target[i]) {
            if(arr[i] < target[i] || i == n-1){
                ok = false;
                break;
            }

            ll diff = arr[i] - target[i];
            arr[i] -= diff;
            arr[i+1] += diff;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}