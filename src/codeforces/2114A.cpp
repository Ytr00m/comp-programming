// Problem: Square Year

#include <bits/stdc++.h>

using namespace std;

void search(int target) {
    int a = 0, b = target;
    int mid, r;
    while(a < b) {
        mid = (a+b)/2;
        r = (a+b) * (a+b);
        if ( r > target){
            if (b == mid) mid--;
            b = mid;

        
        }else if (r < target){
            if (a == mid) mid++;
            a = mid;
        }else {
            cout << a << " " << b << endl;
            return;
        }
    }

    if ((a+b) * (a+b) == target) {
        cout << a << " " << b << endl;
        return;
    }
    cout << -1 << endl;

}
int main() {
    int y;
    int t; cin >> t;
    while(t--) {
        cin >> y;
        search(y);
    }
    
}