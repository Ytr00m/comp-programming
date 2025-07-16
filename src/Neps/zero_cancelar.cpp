#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N;
int resultado;
int X;
int main() {
    vector<int> stack;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X;
        if (X == 0) {
            int remover = stack[(int)stack.size() - 1];
            resultado -= remover;
            stack.pop_back();

            continue;
        }

        stack.push_back(X);
        resultado += X;
    }
    
    cout << resultado;
    
    cout << endl;


}