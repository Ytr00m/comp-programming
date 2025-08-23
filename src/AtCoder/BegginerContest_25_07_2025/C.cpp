#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

string strings[MAXN];
vector<string> conju;
int N, K, X;
int cont;
void permute(int x, int size, string s) {
    s += strings[x];
    size += 1;
    if (size == K) {
        conju.emplace_back(s);
        cont++;
        // cout << s << endl;
        return;
    }
    for(int i = 0; i<N ; i++) {
        permute(i, size, s);
    }

}
int main() {
    cin >> N >> K >> X;

    for(int i=0; i<N;i++) {
        cin >> strings[i];
    }

    for (int i = 0; i<N ; i++) {
        permute(i, 0, "");
    }

    sort(conju.begin(), conju.end());
    cout << conju[X-1] << endl;
}