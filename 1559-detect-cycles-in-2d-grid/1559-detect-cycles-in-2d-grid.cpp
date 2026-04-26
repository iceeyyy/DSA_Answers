class Solution {
public:
    bool dfs(int x,int y ,int px, int py,vector<vector<char>>& grid,vector<vector<int>>& vis,vector<vector<int>>& dir){
        if(vis[x][y]==true){
            return true;
        }

        int n=grid.size();
        int m=grid[0].size();

        vis[x][y]=true;

        for(auto it:dir){
            int newX = x+it[0];
            int newY = y+it[1];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m)
                continue;

            if (grid[newX][newY] != grid[x][y])
                continue;

            if (!vis[newX][newY]) {
                if (dfs(newX, newY, x, y, grid, vis, dir))
                    return true;
            }
            else if (newX != px || newY != py) {
                return true; // visited and not parent -> cycle
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,false));

        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && dfs(i,j,i,j,grid,vis,dir)){
                    return true;
                }
            }
        }

        return false;
    }
};