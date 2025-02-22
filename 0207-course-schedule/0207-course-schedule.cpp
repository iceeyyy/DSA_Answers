class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegr(numCourses,0);
        for(auto pre:prerequisites){
            int course=pre[0];
            int prereq=pre[1];
            adjList[prereq].push_back(course);
            inDegr[course]++;
        }

        vector<int> topo;
        queue<int> q;
        int n=inDegr.size();
        for(int i=0;i<n;i++){
            if(inDegr[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adjList[node]){
                inDegr[it]--;
                if(inDegr[it]==0) q.push(it);
            }
            topo.push_back(node);
        }

        if(topo.size()==numCourses) return true;

        return false;
    }
};