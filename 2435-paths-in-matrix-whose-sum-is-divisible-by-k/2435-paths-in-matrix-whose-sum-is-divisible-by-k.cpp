class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int j,int rem,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int k){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i>=n || j>=m ) return 0; //out of bounds

        if(i==n-1 && j==m-1){
            //destiantion reached
            return (rem + grid[i][j]) % k==0;
        }

        if(dp[i][j][rem]!=-1) return dp[i][j][rem]; //memoization check

        int right =  solve(i,j+1,(rem+grid[i][j]) % k,grid,dp,k); //moving right
        int down = solve(i+1,j,(rem+grid[i][j]) % k,grid,dp,k); //moving down

        return dp[i][j][rem]= (right+down) % mod ;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));

        return solve(0,0,0,grid,dp,k);
    }
};