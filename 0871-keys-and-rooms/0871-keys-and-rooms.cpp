class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms,vector<int>& vis){
        vis[i]=1;

        for(auto it:rooms[i]){
            if(vis[it]!=1){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);

        dfs(0,rooms,vis);

        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }

        return true;
    }
};