class Solution {
public:
    int uniquePaths(int m, int n) {
        //tabulation solution for better space complexity
        vector<vector<int>> dp(m,vector<int> (n));
        //Base Case
        

        //trying all possible values of rows and cols
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int bottom=0;
                    int right=0;
                    if(i>0) bottom=dp[i-1][j];
                    if(j>0) right=dp[i][j-1];
                    
                    dp[i][j]=bottom+right;

                } 
            }
        }
        return dp[m-1][n-1];
    }
};