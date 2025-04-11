class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //tabulized solution
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n));

        for(int i=0;i<n;i++){
            //setting up base cases
            dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0 ;i--){
            for(int j=i;j>=0;j--){
                //moving bottom
                int bottom=triangle[i][j]+dp[i+1][j];
                //moving bottomRight
                int bottomRight=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(bottom,bottomRight);
            }
        }
        return dp[0][0];
    }
};