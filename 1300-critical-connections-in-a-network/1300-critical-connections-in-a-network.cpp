class Solution {
    int t=0;
public:
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,vector<int>& tm,vector<int>& ltm,vector<vector<int>> &ans){
        vis[node]=1;
        tm[node]=ltm[node]=t;
        t++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,tm,ltm,ans);
                ltm[node]=min(ltm[node],ltm[it]);
                if(ltm[it]>tm[node]){
                    //it is a bridge then
                    ans.push_back({it,node});
                }
            }
            else{
                ltm[node]=min(ltm[node],ltm[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        vector<int> tm(n);
        vector<int> ltm(n);
        vector<vector<int>> ans;
        dfs(0,-1,adj,vis,tm,ltm,ans);

        return ans;
    }
};