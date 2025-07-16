#include <bits/stdc++.h>

int alunos[100000];

using namespace std;
int main() {

	int N; cin >> N;
	for (int i=0;i<N;i++) cin >> alunos[i];

	int max_a = alunos[N-1];
	int cont = 0;
	for (int i=N-2;i>=0;i--) {
		if (alunos[i] <= max_a) cont++;

		max_a = max(max_a, alunos[i]);
	}

	cout << cont << endl;
}
