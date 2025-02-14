class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {  // Now adj[node] is a vector<int>, so it can be iterated over
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> adj[n];  

    // Creating adjacency list from adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {  
        if (!vis[i]) {
            cnt++;
            dfs(i, adj, vis);
        }
    }
    
    return cnt;
}
};
