#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 100000;
int P, S, U, V;
pair<int, int> intervalo_atual = {INF, -INF};

int main() {
    cin >> P;
    cin >> S;

    vector< pair<int, int> > intervals;

    intervalo_atual = {0, P};
    
    for (int i = 0; i < S-1; i++)
    {
        cin >> U;
        cin >> V;

        intervalo_atual.first = min(intervalo_atual.first, U);
        int last_second = intervalo_atual.second;
        intervalo_atual.second = max(intervalo_atual.second, V);

        if (intervalo_atual.second < U) {
            cout << intervalo_atual.first << " " << last_second << endl;
        }

    }

    cin >> U;
    cin >> V;

    if (intervalo_atual.second < U) {
        cout << intervalo_atual.first << " " << intervalo_atual.second << endl;
        cout << U << " " << V << endl;

    } else {
        intervalo_atual.first = min(intervalo_atual.first, U);
        intervalo_atual.second = max(intervalo_atual.second, V);
        cout << intervalo_atual.first << " " << intervalo_atual.second << endl;

    }



    


}