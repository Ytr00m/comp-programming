#include <bits/stdc++.h>

using namespace std;
int E, S, L;


int main () {
	cin >> E >> S >> L;

	cout << min(
		abs(E-S) + abs(S-L) + abs(E-L), // E -> S -> L -> E
		abs(L-E) + abs(S-L) + abs(E-S)  // E -> L -> S -> E
	) << endl;
	
}
