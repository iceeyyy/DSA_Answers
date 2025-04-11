class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //tabulized solution
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    // when we reach the desired cell of the grid
                    dp[i][j]=grid[0][0];
                }
                else{
                    // if it goes out of bonds value would be 10^6
                    int bottom=1e6;
                    int right=1e6;
                    if(i>0) bottom=grid[i][j]+dp[i-1][j];
                    if(j>0) right=grid[i][j]+dp[i][j-1];

                    dp[i][j]=min(bottom,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};