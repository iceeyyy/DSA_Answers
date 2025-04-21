class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Tabulation Solution
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        //setting up base cases
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //we are returning dp[n][m] because we shifted the values n is n-1 
        //similarly -1 is 0
        // 0 is 1
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {

        int lcs=2*longestCommonSubsequence(word1,word2);
        int ss=word1.size()+word2.size();
        return ss-lcs;
    }
};