#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;

    int i;
    for (int j = 0; j < n; j++) {
        cin >> i;
        if (i < x){
            x = i;
            cout << 1 << endl;
        }else {
            cout << 0 << endl;
        }
    }

    
}