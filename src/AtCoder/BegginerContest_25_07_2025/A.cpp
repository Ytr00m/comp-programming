#include <bits/stdc++.h>

using namespace std;

string S;
int N, L, R;

int main() {
    cin >> N >> L >> R;
    cin >> S;
    for(int i = L-1; i<R; i++) {
        if (S[i] != 'o') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}