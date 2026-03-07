class Solution {
public:
    bool pos = false;
    vector<int> adj[2*100000];
    bool seen[2*100000];
    void dfs(int v, int destination) {
        if (seen[v] || pos == true) return;

        seen[v] = true;
        if (v == destination){
            pos = true;
            return;
        }

        for ( auto i : adj[v]) {
            if (seen[i] == true) continue;

            dfs(i, destination);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for ( auto edge : edges) {
            int v, i;
            v = edge[0];
            i = edge[1];

            adj[v].push_back(i);
            adj[i].push_back(v);
        }

        pos = false;
        
        dfs(source, destination);

        return pos;
    }
};