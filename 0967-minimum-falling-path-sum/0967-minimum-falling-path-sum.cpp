class Solution {
public: 
    //Tabulized Solution
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n=matrix.size();

        int m=matrix[0].size();

        int ans=INT_MAX;

        vector<vector<int>> dp(n,vector<int> (m,0));

        for(int i=0;i<m;i++){
            //base Case
            dp[n-1][i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0 ;i--){
            for(int j=0;j<m;j++){

                int bottom=matrix[i][j]+ dp[i+1][j];

                int bottomLeft=matrix[i][j];

                int bottomRight=matrix[i][j];
                
                //checking for out of bonds
                if(j-1>=0){
                   bottomLeft+=dp[i+1][j-1];
                }
                //if it is out of bonds
                else{
                    bottomLeft+=1e6;
                }
                //checking for out of bonds 
                if(j+1<m){
                    bottomRight+=dp[i+1][j+1];
                }
                //if it is out of bonds
                else{
                    bottomRight+=1e6;
                }
                dp[i][j]=min({bottom,bottomLeft,bottomRight});
            }
        }
        
        //return the min value possible from the calculated dp
        for(int i=0;i<m;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};