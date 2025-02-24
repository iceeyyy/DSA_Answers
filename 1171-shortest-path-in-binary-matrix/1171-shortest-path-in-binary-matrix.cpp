class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        if(n==1 && grid[0][0]==0) return 1;

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;

        int drow[8]={-1,1,0,0,-1,-1,1,1};
        int dcol[8]={0,0,-1,1,-1,1,-1,1};

        dist[0][0]=1;

        q.push({1,{0,0}});

        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int path=q.front().first;

            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && path+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=path+1;
                    if(nrow==n-1 && ncol==n-1){
                        return path+1;
                    }
                    q.push({path+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};