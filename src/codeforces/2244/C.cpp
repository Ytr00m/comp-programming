#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const int MAXN = 2e5 + 2; 
int parent[MAXN];
int sz[MAXN];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

bool same_set(int a, int b) {
    a = find(a);
    b = find(b);
    return a == b;
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    int x, y; cin >> x >> y;
    for(int i = 1; i <= n; i++){
        if (i - x >= 1) {
            unite(i, i-x);
        }
        if(i + x <= n) {
            unite(i, i+x);
        }

        if(i - y >= 1){
            unite(i, i-y);
        }

        if(i + y <= n) {
            unite(i, i+y);
        }
    }

    bool ok = true;
    for(int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        if(!same_set(i, j)){
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}