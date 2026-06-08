#include <iostream>

int const MAXN = 101;

using namespace std;

int A[MAXN], B[MAXN];

int main() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];

    bool ans = true;
    for(int i = 1; i <= n; i++) {
        if (B[A[i]] != i) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
}
