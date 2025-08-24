// Problem: H. Horóscopo https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/H
#include <bits/stdc++.h>

using namespace std;

vector<int> l_rounds[19];
int champ, N, l_round;
vector<int> times;
int ordem_final[(1 << 18) + 1];


bool comp(int a, int b) {
    return ordem_final[a] < ordem_final[b];
}

int main() {
    cin >> N;
    int qtd_times = (1 << N);

    for(int i=1;i<= qtd_times;i++) {
        cin >> l_round;
        if (l_round == 0) {
            champ = i;
            continue;
        }

        l_rounds[l_round].emplace_back(i);
    }

    ordem_final[0] = champ;
    times.emplace_back(0);

    for(int i = N; i>0 ; i--) {
        sort(times.begin(), times.end(), comp);
        for(int j = 0; j < ( 1 << (N-i) ) ; j++){
            int t1, t2;
            t1 = ordem_final[times[j]];
            t2 = l_rounds[i][j];
            if (t2 < t1) {
                cout << -1 << endl;
                return 0;
            }
            int ind_final_t2;
            ind_final_t2 = times[j] + (1 << (i-1));
            ordem_final[ind_final_t2] = t2;
            times.emplace_back(ind_final_t2);
        }
    }

    for (int i=0; i< (1<<N);i++) {
        cout << ordem_final[i] << " ";
    }
    cout << endl;

}