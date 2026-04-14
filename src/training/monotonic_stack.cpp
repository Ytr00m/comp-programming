#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int main() {
    stack<ll> sf, sg;
    int n; cin >> n;
    vector<ll> arr(n), near_l(n,-1), near_g(n,-1);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        while(!s.empty() && s.top() >= arr[i]){
            sf.pop();
        }

        if (!sf.empty()) near_l[i] = sl.top();

        sf.push(arr[i]);

        while(!sb.empty() && sb.top() <= arr[n-1-i])
    }

    for(auto i : near){
        cout << i << " ";
    }
    cout << endl;
    
}
