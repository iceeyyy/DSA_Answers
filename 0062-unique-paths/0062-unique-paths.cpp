class Solution {
public:
   // this solution is optimized using memoization 
    int dfs(int row,int col,int m,int n,vector<vector<int>>& dp){
        //if it reaches the desired position
        if(row==m-1 && col==n-1){
            return 1;
        }
        // we need to return 0 if robot goes out of bonds
        if(row>=m || row<0 || col>=n || col<0) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col]; //it means it is already calculated 
        
        int l=dfs(row,col+1,m,n,dp); //moving right
        
        int r=dfs(row+1,col,m,n,dp); //moving bottom
        
        return dp[row][col]=l+r;
    }
    int uniquePaths(int m, int n) {
        //using a vector for applying memoization
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return dfs(0,0,m,n,dp);
    }
};