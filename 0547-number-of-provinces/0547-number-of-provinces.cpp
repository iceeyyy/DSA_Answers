class Solution {
public:
    void dfs(int i,vector<vector<int>>& adjList,vector<int>& vis){
        vis[i]=1; //mark as visited

        for(auto u:adjList[i]){
            if(!vis[u]){
                dfs(u,adjList,vis); //call for the next node
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();

        vector<int> vis(n,0);
        vector<vector<int>> adjList(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]){ //if the value is 1
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjList,vis);
            }
        }

        return cnt;
    }
};