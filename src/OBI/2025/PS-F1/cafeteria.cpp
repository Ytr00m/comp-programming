#include <bits/stdc++.h>

using namespace std;


int A, B, C, D;

int main () {
	cin >> A >> B >> C >> D;
	
	int maior_x = (C-A) / D;
	int menor_x = (C-B) / D;

	if (maior_x > menor_x || ((C-B) % D == 0)){
		cout << 'S' << endl;
	
	} else {
		cout << 'N' << endl;
	}
	
}
