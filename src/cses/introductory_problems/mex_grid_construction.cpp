#include <iostream>
#include <set>

using namespace std;

int col_m[101], // current possible mex
    row_m[101], 
    grid[101][101];
int N;
set<int> s_col[101], s_row[101]; // set of elements for each column and row

int find_mex(int i, int j){
    int mex = min(row_m[i], col_m[j]);

    if (i==j) mex=0;
    while (s_row[i].count(mex) != 0 || s_col[j].count(mex)) mex++; // inc till mex isn't in both sets

    row_m[i] = 1 + min(row_m[i], mex);
    col_m[j] = 1 + min(col_m[j], mex);// updates with the minimum possible mex
    s_row[i].insert(mex);
    s_col[j].insert(mex);

    return mex;

}

int main(){

    cin >> N;

    for(int i=0;i < N; i++) {
        for(int j=0; j <= N; j++){
            grid[i][j] = find_mex(i, j);
        }

    }

    for(int i=0; i< N; i++){
        for(int j=0; j < N; j++)
            cout << grid[i][j] << " ";

        cout << "\n";
    }



}
