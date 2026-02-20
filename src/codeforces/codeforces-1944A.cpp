#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve(int n, int k) {
    int ans = n;
    if (k >= n-1)
        ans = 1;

    cout << ans << endl;

}
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        solve(n, k);
    }
}
