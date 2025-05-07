class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        //starting point
        dist[0][0]=moveTime[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto nn=pq.top();
            int timee=nn.first;
            int row=nn.second.first;
            int col=nn.second.second;
            pq.pop();

            if(row==n-1 && col==m-1) return timee;

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){

                    int nextTime = max(timee+1,moveTime[nrow][ncol]+1);

                    if(nextTime < dist[nrow][ncol]){

                        dist[nrow][ncol]=nextTime;
                        pq.push({nextTime,{nrow,ncol}});
                    }

                }
            }
        }
        return -1;
    }
};