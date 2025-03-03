class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto i :adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        if(connections.size()<n-1){
            return -1;
        }
        for(auto i: connections){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i,vis,adj);
            }
        }
        return components-1;
    }
};