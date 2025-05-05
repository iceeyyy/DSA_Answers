class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            //first col
            dp[i][0]=matrix[i][0];
        }
        for(int j=0;j<m;j++){
            //first row
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) dp[i][j]=0;
                else{
                    //taking the minimum possible from taking all possible indices possible in making a square 
                    //top,diagnol,left
                    dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                }
            }
        }
        int ans=0;
        //summing up all the dp table for computing the answer
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dp[i][j];
            }
        }

        return ans;
    }
};