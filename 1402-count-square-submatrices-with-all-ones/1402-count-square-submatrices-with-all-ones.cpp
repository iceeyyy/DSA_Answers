class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        size_t n=matrix.size();
        size_t m=matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(size_t j=0;j<m;j++){
            dp[0][j]=matrix[0][j];  // 1st row would be same 
        }

        for(size_t i=0;i<n;i++){
            dp[i][0]=matrix[i][0]; //1st col would be same as well
        }
        //dp[i][j] represents number of squares ending at that index
        for(size_t i=1;i<n;i++){
            for(size_t j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j]= min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }

        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<m;j++){
                ans+=dp[i][j]; // sum up the dp array
            }
        }
        return ans;
    }
};