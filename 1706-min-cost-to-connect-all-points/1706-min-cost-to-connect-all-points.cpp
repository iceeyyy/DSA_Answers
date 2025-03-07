class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> vis(n ,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //{sum,{x,y}};
        int minSum=0;
        pq.push({0,0});
        //sum=0 and node is 0th
        while(!pq.empty()){
            int sum=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            minSum+=sum;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int nSum=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    pq.push({nSum,i});
                }
            }
        }
        return minSum;
    }
};