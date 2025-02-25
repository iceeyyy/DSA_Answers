class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();

        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        //{diff,{row,col}};
        //top, right,bottom,left
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        dist[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty()){
            int d=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;

            q.pop();

            if(row==n-1 && col==m-1){
                    return d;
            }
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){

                    int neweffort= max (abs(heights[row][col]-heights[nrow][ncol]),d);
                    if(dist[nrow][ncol]>neweffort){
                        dist[nrow][ncol]=neweffort;
                        q.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};