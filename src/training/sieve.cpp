#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    vector<ll> primes;
    ll n; cin >> n;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    int i_loop = 0;
    int a_loop = 0;
    for(ll i = 2; i<=n; i++){
        if (is_prime[i]) {
            a_loop = 0;
            for(ll j = i*i; j <= n; j += i) {
                i_loop++;
                a_loop++;
                is_prime[j] = false;
            }
            if (a_loop > 0)
                cout << "Primo " << i << " => " << a_loop << endl;
        } 
    }
    for(int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    //for(auto i:primes) cout << i << " ";
    cout << "Loop interno => " << i_loop << endl;
    cout << "Media        => " << ((double) i_loop / n) << endl;
    cout << "\n";
}
