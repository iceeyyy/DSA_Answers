class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        

        vector<vector<int>> adjres(n);

        vector<int> inDegree(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adjres[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        // push nodes with zero indegrees inside the queue
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adjres[node]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};