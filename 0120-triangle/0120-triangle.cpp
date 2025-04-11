class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        //applying memoization for better time complexity compared to simple recursion
        int n=triangle.size();
        //if we reach the last row we simply return the element
        if(row==n-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        // going for same index at next row
        int down=triangle[row][col]+solve(row+1,col,triangle,dp);
        //going for same index+1 at next row
        int downRight=triangle[row][col]+solve(row+1,col+1,triangle,dp);

        return dp[row][col]=min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,0,triangle,dp);
    }
};