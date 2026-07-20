#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long s = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            s += tmp;
        }

        if(abs(s) % 4 == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}