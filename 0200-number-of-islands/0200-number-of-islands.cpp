class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> & vis,vector<vector<char>>& grid,int drow[],int dcol[]){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid,drow,dcol);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        int cnt=0;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid,drow,dcol);
                }
            }
        }
        return cnt;
    }
};