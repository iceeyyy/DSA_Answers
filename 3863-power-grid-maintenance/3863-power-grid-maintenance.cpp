class Solution {
public:
    void dfs(int i,int compId,vector<int>& Cid,unordered_map<int,set<int>>& mp,vector<bool>& vis,vector<vector<int>>& adj){
        vis[i]=true;
        Cid[i]=compId;
        mp[compId].insert(i); 

        for(auto it:adj[i]){
            if(!vis[it]){ //compId will be same as of previous 
                dfs(it,compId,Cid,mp,vis,adj);
            }
        }

    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c+1);
        vector<bool> vis(c+1,false);
        vector<int> ans;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); //creating adjacency list
        }

        vector<int> Cid(c+1);
        unordered_map<int,set<int>> mp;

        // CompId => set(elements)

        for(int i=1;i<=c;i++){
            if(!vis[i]){
                int compId=i; //component id
                dfs(i,compId,Cid,mp,vis,adj);
            }
        }

        for(auto q:queries){
            int x = q[1];
            int type = q[0];
            
            if(type==1){
                int Comp = Cid[x];

                if(mp[Comp].count(x)){
                    ans.push_back(x); // already present in the grid as online station
                }
                else if(!mp[Comp].empty()){
                    ans.push_back(*mp[Comp].begin());
                }
                else{
                    ans.push_back(-1); //set is empty
                }

            }
            else{
                //type 2 query 
                int Comp = Cid[x];
                mp[Comp].erase(x);
            }
        }

        return ans;
    }
};