class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq; //min-heap

        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
        }

        vector<vector<int>> ans;
        while(k!=0){
            auto point=pq.top().second;
            pq.pop();
            ans.push_back({point.first,point.second});
            k--;
        }
        return ans;
    }
};