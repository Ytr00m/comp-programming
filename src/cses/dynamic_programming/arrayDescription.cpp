#include <bits/stdc++.h>
#define ll long long

int const MOD  = 1e9 + 7;
int const MAXN = 1e5 + 1;
int const MAXM = 1e2 + 2;
ll dp[MAXN][MAXM];
int arr[MAXN];

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= m; i++){
        if(arr[1] == 0 || arr[1] == i) {
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if( arr[i] == 0 || arr[i] == j) {
                dp[i][j] = (((dp[i-1][j-1] + dp[i-1][j]) % MOD) + dp[i-1][j+1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;


}
