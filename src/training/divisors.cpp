#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    vector<ll> divisores;

    ll n; cin >> n;

    for(ll i = 2; i*i<=n; i++){
         while(n % i == 0){
            divisores.push_back(i);
            n /= i;
        }
    }
    if (n > 1) divisores.push_back(n);

    for(auto i:divisores) cout << i << " ";

    cout << endl;
}
