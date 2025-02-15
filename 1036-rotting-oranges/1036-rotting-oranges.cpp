class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntfresh=0;
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntfresh++;
                }
            }
        }

        int tm=0;
        //t,r,b,l
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;

        while(!q.empty()){
            int r= q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow= r +drow[i];
                int ncol= c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }

        }

        if(cnt!=cntfresh) return -1;

        return tm;


    }
};