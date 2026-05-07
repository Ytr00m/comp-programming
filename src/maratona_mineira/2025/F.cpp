// URL: https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/F
#include <bits/stdc++.h>

#define MOD 998244353
#define ll long long
#define MAXN 1000
#define pii pair<int, int>
#define mp make_pair

using namespace std;

ll fat[1000001];
char grid[MAXN][MAXN];
ll freq[1000001];
ll quejo[1000001];
ll pref[1000001];

int N, M, K, dists;

ll expb(ll a, ll b) {
	if (b == 0) return 1;
	ll res = expb(a, b/2);
	if (b % 2 == 0) return (res*res) % MOD;
	else return (((res*res) % MOD) * a) % MOD;
}

ll inv(ll a) {
	return expb(a, MOD-2);
}

ll bin(ll n, ll k) {
	if ( k > n || n < 0 || k < 0 ) return 0;
	return ((fat[n] * inv(fat[n-k])) % MOD) * inv(fat[k]) % MOD;
}

void to(int x, int y, int d, queue<pair<int, pii>>& q) {
//	cout << "BFS em => " << x << " " << y << endl;
	if (x < 0 || y < 0 || x == N || y == M) return;
	
	if (grid[x][y] == '#') return;

	if (grid[x][y] == 'Q') {
		grid[x][y] = '#';
		quejo[d] = true;
		return;
	}
	
	grid[x][y] = '#';
	freq[d]++;
	q.push(mp(d, mp(x, y)));
	return;
}
void bfs(int x, int y) {
	
	queue<pair<int, pii>> q;
	
	q.push(mp(0, mp(x, y)));
	while(!q.empty()) {
		auto [d, tmp] = q.front(); q.pop();
		auto [v, u]   = tmp;
		
		int nd = d + 1;
		// up
		to(v, u-1, nd, q);
		// down
		to(v, u+1, nd, q);
		// right
		to(v+1, u, nd, q);
		// left
		to(v-1, u, nd, q);
	}
}

ll prob(int tot, int distancia) {
	ll casos_totais = bin(tot, K);

	ll maior_igual = bin(tot-pref[distancia-1], K);
	if (quejo[distancia] == true) {
		return (maior_igual * inv(casos_totais)) % MOD;
	}
	ll maior       = bin(tot-pref[distancia], K);
	ll numerador = (maior_igual - maior) % MOD;
	if (numerador < 0) numerador += MOD;

	//cout << "Prob distancia " << distancia << endl;
	//cout << "Casos totais: " << casos_totais << endl;
	//cout << "Maior igual: " << maior_igual << " => Maior: " << maior << endl; 
	return (numerador * inv(casos_totais)) % MOD;
}

int main () {
	fat[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		fat[i] = i * fat[i-1] % MOD;
	}
	cin >> N >> M >> K;
	char tmp;
	int x, y;
	int tot=0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> tmp;
			grid[i][j] = tmp;
			if (tmp == 'R') {
				x = i; y = j;
			}
			if (tmp == '.') tot++;
		}
	}
	
	grid[x][y] = '#';
	bfs(x, y);

	//cout << "QTD d => " << dists << endl;	
	int j = 1;
	while ( j <= N * M ) {
		//cout << "FREQ "<<  j << " => " << freq[j] << endl;
		//cout << "i = " << i << endl;
		pref[j] = pref[j-1] + freq[j];

		if (freq[j] == 0) break;
		j++;
	}

	j = 1;

	ll ans = 0;

	while (j <= N * M) {
		if (freq[j] > 0 || quejo[j] == true){
			ll p =  prob(tot, j);
			//cout << "Calculando distancia " << j << " => Prob = " << p << endl;
			ans = (ans + ( (j * p) % MOD) % MOD);
			if (quejo[j] == true) break;
		} else break;
		j++;	
	}

	cout << ans % MOD << endl;
}
