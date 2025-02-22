class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n,0);

        vector<int> ans;
        for(auto &pre: prerequisites){
            int course=pre[0];
            int preq=pre[1];
            adjList[preq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                //push the node with inDegree zero inside the queue to start
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adjList[node]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            
        }
        if(ans.size()!=n){
            ans.clear();
        }
        return ans;
    }
};