class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>& mp,vector<bool>& vis,int &result){
        vis[u]=true;
        for(auto adj:mp[u]){
            int v=adj.first;
            int dist=adj.second;

            result=min(result,dist);

            if(!vis[v]){
                dfs(v,mp,vis,result);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mp;

        for(auto &vec:roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];
            mp[u].push_back({v,dist});
            mp[v].push_back({u,dist});
        }

        vector<bool> vis(n+1,false);

        int result=INT_MAX;

        dfs(1,mp,vis,result);

        return result;
    }
};