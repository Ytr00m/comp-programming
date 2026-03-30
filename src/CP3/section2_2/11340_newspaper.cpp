#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, double> table;
double ans;

void solve() {
	int k; cin >> k;
	for( int i = 0; i<k; i++){
		char key; cin >> key;
		double v; cin >> v;
		table[key] = v;
	}

	int m; cin >> m;
	ans = 0;
	string line;

	for( int i = 0; i<m;i++){
		cin >> line;
		for( char c : line){
			if (table.find(c) != table.end()) ans += table.find(c);
		}
	}

	cout << setprecision(2);
	cout << fixed;
	cout << ans << "$" << endl;
}
int main() {

	int n; cin >> n;
	while(n--) solve();


}
