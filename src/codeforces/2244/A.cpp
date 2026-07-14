#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    int n;
    while(t--) {
        cin >> n;
        int ans = 0;
        int len = 0;
        char c;
        for(int i = 0; i < n; i++){
            cin >> c;
            if(c == '#') len++;
            if(c == '*'){
                ans = max(ans, (len/2) + (len % 2));
                len = 0;
            }
        }
        ans = max(ans, (len/2) + (len % 2));

        cout << ans << "\n";
    }
}
