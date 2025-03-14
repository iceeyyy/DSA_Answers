class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(auto i:points){
            int x=i[0];
            int y=i[1];
            int dist=x*x + y*y;
            pq.push({dist,{x,y}});
        }
        vector<vector<int>> ans;
        while(k!=0){
            auto coor=pq.top().second;
            int x=coor.first;
            int y=coor.second;
            pq.pop();
            ans.push_back({x,y});
            k--;
        }
        return ans;
    }
};