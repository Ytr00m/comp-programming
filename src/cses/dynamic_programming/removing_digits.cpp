// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define INF 1000001
int n;
int dp[INF];

int findMin(int target, int x) {
    if (x == 0) return INF;

    // cout << x << endl;
    int dig = x % 10;
    int carry = x / 10;
    int pos_min_dp = target - dig;
    //cout << dig << " " << carry << " " << pos_min_dp << " " << dp[pos_min_dp] << endl;
    return min(dp[pos_min_dp], findMin(target, carry));
}
int main() {;

    dp[0] = INF;
    for (int i=1; i < 10; i++) {
        dp[i] = 1;
    }

    cin >> n;
    if (n < 10) {
        cout << dp[n] << endl;;
        return 0;
    }

    for(int i=10; i<n+1; i++) {
        dp[i] = INF;
        dp[i] = findMin(i, i) + 1;
        //cout << i << " => " << dp[i] << endl; 
    }

    cout << dp[n];

    // for(int i=0; i<n+1; i++) {
    //     cout << i << " => " << dp[i] << endl; 
    // }
    
}
