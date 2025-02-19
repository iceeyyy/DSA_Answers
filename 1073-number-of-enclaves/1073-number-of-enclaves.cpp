class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int drow[],int dcol[]){
        //To solve the memory limit exceeded error, I passed the grid as a reference, which stopped the making of unnecessary copies of the grid.
        vis[row][col]=1;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,drow,dcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j]&& grid[0][j]==1){
                dfs(0,j,vis,grid,drow,dcol);
            }
            //last row
            if(!vis[n-1][j]&& grid[n-1][j]==1){
                dfs(n-1,j,vis,grid,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,drow,dcol);
            }
            //last col
            if(!vis[i][m-1]&& grid[i][m-1]==1){
                dfs(i,m-1,vis,grid,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};