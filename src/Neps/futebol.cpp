#include <iostream>
#define MAXN 100000

using namespace std;
int arr[MAXN];
int arr_compl[MAXN];
int N, v, x;
int ind1 = MAXN, ind2 = MAXN;

int main () {
    fill(arr_compl, arr_compl+MAXN, -1);
    
    cin >> N >> x;
    for(int i=0;i<N;i++){
        cin >> v;
        arr[i] = v;
        if (arr_compl[v] == -1 ) {
            arr_compl[v] = i;
            continue;
        }

        arr_compl[v] = min(arr_compl[v], i);
    }

    for(int i=0;i<N;i++) {
        int c;
        if(arr[i] >= x) {
            c = arr[i] - x;
        } else {
            c = arr[i] + x;
        }

        if (arr_compl[c] == -1) continue;

        if (arr_compl[c] < ind1 && i < ind2 || arr_compl[c] < ind2 && i < ind1) {
            ind1 = arr_compl[c];
            ind2 = i;
        }
    }

    if (ind1 > ind2) {
        swap(ind1, ind2);
    }

    for(int i=0;i<10;i++) {
        cout << arr_compl[i] << " ";
    }

    cout << endl;

    if (ind1 == MAXN && ind2 == MAXN) {
        ind1 = ind2 = -1;
    }
    
    cout << ind1 << " " << ind2 << endl;
    

    
}