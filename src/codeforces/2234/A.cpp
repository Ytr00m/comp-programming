#include <bits/stdc++.h>


using namespace std;


void solve() {
    multiset<int> seen;
    vector<int> arr;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
        seen.insert(tmp);
    }
    sort(arr.rbegin(), arr.rend());
    //cout << "inseriu inicialmente "<< endl;
    for(int i = 0; i < n - 1; i++) {
        for( int j = i+1; j < n; j++) {
            vector<int> to_insert;
            int x, y;
            x = arr[i];
            y = arr[j];
            //cout << "numeros pegos => " << x << " " << y << "\n";
            //cout << " antes de inserir x e y " << endl;
            seen.erase(seen.find(x));
            seen.erase(seen.find(y));
            to_insert.push_back(x);
            to_insert.push_back(y);
            int k = n;
            int ai = x;
            int ai1 = y;
            bool can = true;
            for( int l = 1; l <= k-2; l++) {
                int ai2 = ai % ai1;
                auto it = seen.find(ai2);
                if( it == seen.end()) {
                    can = false;
                    break;
                } else {
                    ai  = ai1;
                    ai1 = ai2;
                    ai2 = *it;
                    seen.erase(it);
                    to_insert.push_back(ai2);
                    //cout << "inseriu " << ai2 << endl;
                }
            }
            
            if(can) {
                cout << x << " " << y << "\n";
                return;
            }

            //cout << " saiu primeiro for com " << to_insert.size() << " para inserir" << endl;
            for( int l : to_insert ) {
                seen.insert(l);
                //cout << "reinserindo " << l << endl;
            }
        } 
    }

    cout << -1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) solve();

}
