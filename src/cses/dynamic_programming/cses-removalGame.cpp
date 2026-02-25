// Source: https://usaco.guide/general/io
// https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[5001];
ll pref[5001];
ll dp[5001][5001];
int seen[5001][5001];

ll total(int i, int j){
    if (i==j) {
        return arr[i];
    } else{
        return pref[j] - pref[i-1];
    }
}

//rec version
ll dpr(int i, int j){
    if (i > j) return 0;
    if (i == j) return arr[i];

    if (seen[i][j]) return dp[i][j];

    dp[i][j] = max(
        // pick the left
        total(i, j) - dpr(i+1, j),
        total(i, j) - dpr(i, j-1)
    );

    seen[i][j] = 1;

    return dp[i][j];

    
}
int main() {
    // read n
    int n; cin >> n;

    // read each value
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // calc the prefix sum
    pref[0] = arr[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + arr[i];
    }

    // the dp:
    // I can either pick the right or the left
    // if i pick the left, my score will be
    // the one that i 
    // total - bestPossible[i+1][j]
    // and if i pick the right, my sc will be
    // total - bestPossible[i][j-1]
    // the base case is 
    // bestPossible[i][i] = arr[i]

    // Iterative version:
    // Calculate the states by interval length 
    // first length 1, after 2, and so on to n
    /*
    for( int j = 0; j < n; j++){
        for (int i = 0; i < n - j; i++){
            cout << "======" << endl;
            cout << i << " " << i+j << endl;
            cout << "Total: " << total(i, i+j) << endl;
            dp[i][i+j] = max(
                // Pick the most left
                total(i, i+j) - dp[i+1][i+j],
                // Pick the most right
                total(i, i+j) - dp[i][i+j-1]
            );
            cout << "Dp: " << dp[i][i+j] << endl;
            cout << "======" << endl;
        }
    }
    */

    //cout << dp[0][n-1] << endl;

    cout << dpr(0, n-1) << endl;
   /* print the dp
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    
}
