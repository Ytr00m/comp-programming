class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> grau_entrada(n, 0);
        vector<int> grau_saida(n, 0);

        for ( auto edge : trust) {
            grau_saida[edge[0]-1]++;
            grau_entrada[edge[1]-1]++;
        }

        int qtd_ans = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (grau_saida[i] == 0 && grau_entrada[i] == n-1){
                qtd_ans++;
                ans = i+1;
            }
        }

        if (qtd_ans == 1) {
            return ans;
        } else {
            return -1;
        }

    }
};