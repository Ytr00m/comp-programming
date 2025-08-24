#include <bits/stdc++.h>

using namespace std;

string S;

int main() {
    cin >> S;
    bool print = true;
    for(auto c : S) {
        
        if (print && c != '#') {
            cout << "o";
            print = false;
        }else {
            cout << c;
            if (c == '#') {
                print = true;
            }
        }
    }

    cout << endl;
}