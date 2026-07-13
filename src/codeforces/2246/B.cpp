#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve() {
    int n; cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n == 2) cout << -1 << endl;
    else {
        long long s = 3;
        cout << "1 2 ";
        for(int i = 0; i < (n-2); i++){
            cout << s << " ";
            s += s;
        }
        cout << endl;
    } 
}
int main() {
    int t; cin >> t;

    while(t--){
        solve();
    }
}