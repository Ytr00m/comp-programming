#include <bits/stdc++.h>
#include <vector>
using namespace std;

int MAXT = 50000;
int N;
int tempo_ligada;
int instante_anterior = -MAXT;
int main() {
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int instante_atual;
        cin >> instante_atual;

        tempo_ligada -= 10 - min(10, instante_atual - instante_anterior);

        tempo_ligada += 10;

        instante_anterior = instante_atual;
    }

    cout << tempo_ligada;
    
    cout << endl;


}