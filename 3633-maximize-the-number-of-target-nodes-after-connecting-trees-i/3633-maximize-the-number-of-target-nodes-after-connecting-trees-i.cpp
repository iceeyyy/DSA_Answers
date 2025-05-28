class Solution {
public:
    int BFS(int start,vector<vector<int>>& adj,int k){
        queue<pair<int,int>> q;
        //{node,parent}
        q.push({start,-1});
        int count=0;

        while(!q.empty() && k>=0){
            int size = q.size();
            count+=size;

            for(int i=0;i<size;i++){
                auto cur = q.front();
                q.pop();

                int u = cur.first;
                int parent = cur.second;
                for(auto v:adj[u] ){
                    if(v!=parent){
                        q.push({v,u});
                    }
                }
            
            }
            k--;
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(auto it:edges1){
            int u = it[0];
            int v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto it:edges2){
            int u = it[0];
            int v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int maxx=0;
        //calculating max reachable nodes in tree2 
        for(int i=0;i<=m;i++){
            int maxi = BFS(i,adj2,k-1);
            maxx = max(maxx,maxi);
        }
        vector<int> ans(n+1);

        for(int i=0;i<=n;i++){
            //calculating maxx nodes from tree1 with every node and adding maxx possible nodes from tree2
            ans[i] = BFS(i,adj1,k) + maxx;
        }
        return ans;
        
    }
};