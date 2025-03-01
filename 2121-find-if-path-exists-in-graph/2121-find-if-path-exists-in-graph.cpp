class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<int> vis(n);
       vector<vector<int>> adj(n);
       queue<int> q;
       for(auto i : edges){
        int u=i[0];
        int v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       } 
       vis[source]=1;
       q.push({source});
       while(!q.empty()){
        int node=q.front();
        q.pop();
        vis[node]=1;
        if(node==destination) return true; //there is a path between src and destination

        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it});
            }
        }
       }

       return false;
    }
};