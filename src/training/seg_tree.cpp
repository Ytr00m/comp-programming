#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>

#define ll long long
#define MAXN (int)1e6+5

using namespace std;
const string NODE_INDICATOR = "|___";
const string IDENTATION     = "             ";


ll arr[MAXN];
ll tree[4*MAXN];
ll N;

ll mg(ll a, ll b) {
    //return min(a, b);
    //return max(a, b);
    return a + b;
}

ll build(int node, int l, int r){
    if (l == r){
        return tree[node] = arr[l];
    }
    int mid = (l+r) / 2;

    tree[node] = mg(build(2*node, l, mid), build(2*node+1, mid+1, r));
    return tree[node];
}

void printTree(int node, int l, int r, int depth = 0){    
    int mid = (l+r) / 2;
    if (l != r) {
        printTree(node*2 + 1, mid+1, r, depth+1);
    }

    for(int i = 0; i < depth; i++) cout << IDENTATION;
    
    cout << NODE_INDICATOR << " ";
    cout << "[" << l << ", " << r << "] " << tree[node] << endl;

    if (l != r){
        printTree(node*2, l, mid, depth+1);
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];

    build(1, 0, N-1);

    printTree(1, 0, N-1);

    cout << endl;
    for(int i = 1; i <= 4*N; i++) cout << setw(3) << i << " ";
    cout << endl;


    for(int i = 1; i <= 4*N; i++) cout << setw(3) << tree[i] << " ";
    cout << endl;
}
