class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        //memoized solution for better time complexity
        int n=grid.size();
        int m=grid[0].size();
        //it it goes out of bonds (Base Case 1)
        if(row>=n || col>=m){
            return 1e6;
        }
        //if it reaches the desired index (Base Case 2)
        if(row==n-1 & col==m-1){
            return grid[n-1][m-1];
        }
        if(dp[row][col]!=-1) return dp[row][col];

        int bottom=grid[row][col]+solve(row+1,col,grid,dp);
        int right=grid[row][col]+solve(row,col+1,grid,dp);

        return dp[row][col]=min(bottom,right);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(0,0,grid,dp);
    }
};