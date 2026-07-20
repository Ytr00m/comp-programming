#include <bits/stdc++.h>
#define endl "\n"

using ll = long long;
using namespace std;

void solve() {
    ll m;
    int n, k; cin >> n >> k >> m;
    if(k > m) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll s = 0;
    vector<ll> arr(n, 0);
    int l = 0;
    int r = 0;
    while(r < n){
        if(r - l + 1 < k){
            arr[r] = 1;
            s += 1;
            r++;
        }else {
            ll t = (m - s) + m*r;
            s -=  arr[l];
            s += t;
            arr[r] = t;
            l++;
            r++;
        }
    }

    for(auto i : arr) cout << i << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();
    
}