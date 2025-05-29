class Solution {
public:
    int bfs(int start,vector<vector<int>>& adj,vector<bool>* included = NULL){
        queue<pair<int,int>> q;
        q.push({start,-1});

        int count = 0;
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            if(level%2==0){
                count+=size;
            }
            for(int i=0;i<size;i++){
                auto node = q.front();
                int cur = node.first;
                int parent = node.second;
                q.pop();
                if(included && level %2 ==0){
                    (*included)[cur] = true;
                }
                for(auto v :adj[cur]){
                    if(v==parent) continue;
                    q.push({v,cur});
                }
            }
            level++;
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(auto it : edges1){
            int u = it[0];
            int v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto i:edges2){
            int u=i[0];
            int v=i[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        //best possible in tree2 couting nodes at even level and rest are at odd level
        int even_count2 = bfs(0,adj2);
        int odd_count2 = m - even_count2;
        int best2 = max(even_count2,odd_count2);

        vector<bool> included(n,false);
        //for recording nodes at even level in tree1
        int even_count1 = bfs(0,adj1,&included);

        vector<int> ans(n);
        // trying to connect every level of tree1 with best possible node of tree2
        for(int i=0;i<n;i++){

            if(included[i]){
                //nodes present at even level
                ans[i] = even_count1 +best2;
            }
            else{
                //nodes at odd level
                ans[i] = (n - even_count1)+best2;
            }
        }

        return ans;
    }
};