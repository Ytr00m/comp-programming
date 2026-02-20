#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int start = -1;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == n) {
                start = i;
            }
        }
        int i, j;
        i = j = start;
        int k = 1;
        bool imp = false;
        while(j - i + 1 != n) {
            if (arr[i-1] == n-k) {
                i--;k++;
            } else if(j < n && arr[j+1] == n-k) {
                j++;k++;
            } else {
                imp = true;
                break;
            }
        }

        cout << (imp ? "NO" : "YES") << endl;

    }

}
