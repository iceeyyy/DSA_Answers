class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //tabulized solution
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    //if there's an obstacle on the grid (Base Case)
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                    //Base Case 
                    dp[i][j]=1;
                }
                
                else{
                    //if it goes out of bonds it will return 0 
                    int bottom =0;
                    int right=0;
                    if(i>0){
                        //going bottom
                        bottom=dp[i-1][j];
                    }
                    if(j>0){
                        right=dp[i][j-1];
                    }
                    dp[i][j]=bottom+right;
                }
            }
        }
        return dp[n-1][m-1];
    }
};