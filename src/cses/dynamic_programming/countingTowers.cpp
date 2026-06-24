#include <bits/stdc++.h>
#define ll long long

int const MOD  = 1e9 + 7;
int const MAXN = 1e6 + 1;
ll dp[MAXN][2];

using namespace std;

int main() {
    dp[1][0] = dp[1][1] = 1;

    for(int i = 2; i < MAXN; i++) {
        dp[i][0] = (((4 * dp[i-1][0]) % MOD) + dp[i-1][1]) % MOD;
        
        dp[i][1] = (((2 * dp[i-1][1]) % MOD) + dp[i-1][0]) % MOD;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }


}
