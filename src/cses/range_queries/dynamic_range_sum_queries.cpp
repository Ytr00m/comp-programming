#include <bits/stdc++.h>

const int MAXN = 2e5 + 5;
#define ll long long
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll arr[MAXN];
ll bit[MAXN];
int N, Q;

void update(int i, int x){
    while(i <= N){
        bit[i] += x;
        i += i & -i;
    }
}
ll sum(int i){
    ll ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

ll query(int a, int b){
    return sum(b) - sum(a-1);
}

int main () {
    fast_io();

    cin >> N >> Q;

    ll tmp;
    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        arr[i] = tmp;
        update(i, tmp);
    }

    int a, b, c;
    for(int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - arr[b]);
            arr[b] = c;
        } else {
            cout << query(b, c) << endl;
        }
    }
   
    /*
    cout << "Indice => ";
    for(int i = 1; i <= N; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Array  => ";
    for(int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    cout << "LSB    => ";
    for(int i = 1; i <= N; i++) {
        cout << (i & -i) << " ";
    }
    cout << endl;
    cout << "BIT    => ";

    for(int i = 1; i <= N; i++) {
        cout << bit[i] << " ";
    }
    cout << endl;
    */
}
