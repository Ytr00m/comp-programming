// Link: https://codeforces.com/gym/106073/problem/M
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int const MAXN = 1e5 + 2;
ll const INF   = 1e18 + 1;

ll arr[MAXN], 
   tree[4*MAXN],
   lazy[4*MAXN];

int N, K;

ll build(int node, int l, int r) {
    if (l == r) return tree[node] = arr[l];
    int mid = (l + r) / 2;

    return tree[node] = min(build(node*2, l, mid), build(node*2 + 1, mid+1, r));
}

void propagate(int node, int l, int r) {
    if (lazy[node] ==  0) return;

    tree[node] += lazy[node];
    if (l != r) {
        lazy[node*2] += lazy[node];
        lazy[node*2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}
ll query(int node, int L, int R, int l, int r) {
    propagate(node, L, R);
    if (L > r || R < l) return INF;
    if (L >= l && R <= r) return tree[node];
    int mid = (L + R) / 2;

    return min(query(node*2, L, mid, l, r), query(node*2 + 1, mid+1, R, l, r));
}
void update(int node, int L, int R, int l, int r, ll value){
    propagate(node, L, R);
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        lazy[node] += value;
        propagate(node, L, R);
        return;
    }
    int mid = (L + R) / 2;
    update(node*2, L, mid, l, r, value);
    update(node*2 + 1, mid+1, R, l, r, value);

    tree[node] = min(tree[node*2], tree[node*2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    ll ans = INF;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        ans = min(ans, arr[i]);
    }

    build(1, 1, N);

    int l, r;
    l = r = 1;
    while(r <= N) {
        // cout << l << " " << r << endl;
        if (l-1 <= r-1){
            // cout << l-1 << " " << r-1 << endl;
            
            update(1, 1, N, l-1, r-1, -1);
        }
        update(1, 1, N, r, r, K);
        ans = max(ans, query(1, 1, N, 1, N));
        
        r++;
        if (r - l + 1 > K) l++;
    }

    cout << ans << endl;
}