#include <bits/stdc++.h>
#include <vector>
using namespace std;

int MAXN = 50000;
int N;
int M;
int main() {
    vector<int> fila;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int ind;
        cin >> ind;
        fila.push_back(ind);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int ind_saiu;
        cin >> ind_saiu;

        for (int j = 0; j < (int)fila.size(); j++)
        {
            if (fila[j] == ind_saiu) {
                fila.erase(fila.begin() + j);
                break;
            }
        }
        
    }

    for (int i = 0; i < (int)fila.size(); i++)
    {
        cout << fila[i] << " ";
    }
    
    cout << endl;


}