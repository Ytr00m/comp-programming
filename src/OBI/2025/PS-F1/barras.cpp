#include <bits/stdc++.h>


using namespace std;

int graph[100][100];
int list[100];
int main() {

	int N;
	cin >> N;

	int maxi = 0;
	for(int i=0;i<N;i++) {
		int x;

		cin >> x;
		maxi = max(maxi, x);
		int dif = 100 - x;
		for (int j=dif;j<100;j++) {
			graph[j][i] = 1;
		}
	}

	int dif = 100 - maxi;
	for (int i=dif;i<100;i++) {
		for (int j=0;j<N;j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

}
