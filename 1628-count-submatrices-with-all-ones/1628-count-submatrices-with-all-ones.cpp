class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        size_t row=mat.size();
        size_t col=mat[0].size();
        int ans=0;
        vector<vector<int>> dp(row,vector<int> (col));

        for(size_t i=0;i<row;i++){
            int cnt=0; //precomputing consecutive ones
            for(int j=col-1;j>=0;j--){  // changed to int because of false overflow condition
                if(mat[i][j]==1){
                   cnt++;
                }
                else{
                    cnt=0;
                }
                dp[i][j]=cnt;
            }
        }

        for(size_t i=0;i<row;i++){
            for(size_t j=0;j<col;j++){
                int x=INT_MAX;
                for(size_t k=i;k<row;k++){
                    x=min(x,dp[k][j]);
                    ans+=x;
                }
            }
        }

        return ans;
    }
};