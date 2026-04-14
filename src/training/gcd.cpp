#include <iostream>

#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


int main() {
    ll a, b; cin >> a >> b;
    ll mdc = gcd(a, b);

    cout << "GCD: " << mdc << endl;
    cout << "Frac Irred: " << a/mdc << " " << b/mdc << endl;
}
