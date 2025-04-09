class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        //out of bonds
        if(row>=n || col>=m){
            return 0;
        }
        //obstacle is present in the path so it is not possible
        if(obstacleGrid[row][col]==1) return 0;

        //destination reachead 
        if((row==n-1) && (col==m-1)){
            return 1;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        
        int r=solve(row,col+1,obstacleGrid,dp); //moving right
        int b=solve(row+1,col,obstacleGrid,dp); //moving bottom

        return dp[row][col]=r+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return solve(0,0,obstacleGrid,dp);
    }
};