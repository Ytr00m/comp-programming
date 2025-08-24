#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> child;
int n, x, ans;

int main(){
    cin >> n >> x; // n = childs; x = maximum weight per gondola

    int w; // child weight
    for(int i = 0; i < n; i++){
        cin >> w;
        child.push_back(w);
    } 

    sort(child.begin(), child.end());

    int l = 0, r = n-1;
    while(l <= r){

        if (child[l] + child[r] <= x){
            // l and r is in the range of x
            // +1 gondola for both together
            ans++;
            l++;
            r--;
        } else {
            // l and r is not in the range of x
            // +1 gondola for r
            ans++;
            r--;
        }
    }

    cout << ans << endl;

}
