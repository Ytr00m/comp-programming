// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;

int main() {
    /*
    base case:
    ==
    to transform the str '' in b,
    it suffices to do b.lenght() operations
    of insert, and vice versa
    ==

    if a[i] == b[j], so the number of operations
    to transform the first i characters of a
    into the j characters of b is the same number
    of operations to transform the first
    i-1 characters of a into j-1 of b.

    if a[i] != b[j], so the answer is
    the minimum in:
    - the number of operations to transform 
    the first i-1 characters of a
    into the first j characters of b
    + delete the character at the i position
    in a

    - the number of operations to transform 
    the first i charaters of a into the first
    j-1 characters of b 
    + insert the b[j] character to the end of
    a

    - the number of operations to transform the
    first i-1 characters of a into the first
    j-1 characters of b 
    + update a[i] to b[i]
    
    */

    string a, b; cin >> a >> b;
    vector<int> ant(5001), cur(5001);
    // base cases
    for (int i = 0; i <= b.size(); i++){
        ant[i] = i;
        //cout << ant[i] << " ";
    }
    //cout << endl;
    
    for (int i = 0; i <= (int)a.size(); i++){
        cur[0] = i+1;
        for (int j = 0; j <= (int)b.size(); j++){
            if (a[i] == b[j]){
                cur[j+1] = ant[j];
            } else {
                cur[j+1] = min({
                    ant[j+1],
                    cur[j],
                    ant[j]
                }) + 1;
            }

            //cout << cur[j+1] << " ";
        }
        //cout << endl;
        ant = cur;
    }

    cout << cur[b.size()+1] << endl;
}
