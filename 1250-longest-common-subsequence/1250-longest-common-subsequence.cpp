class Solution {
public:
    int solve(int ind1,int ind2,string& text1, string& text2,vector<vector<int>>& dp){
        //base case
        if(ind1==text1.size()|| ind2==text2.size()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //if characters match
        if(text1[ind1]==text2[ind2]){
            return 1+ solve(ind1+1,ind2+1,text1,text2,dp);
        }
        // if it doesn't match their are two possibilites either we increment ind1 or ind2 
        // and we want the longest subseq so we return  the max
        return dp[ind1][ind2] = max(solve(ind1+1,ind2,text1,text2,dp),solve(ind1,ind2+1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();

        int m=text2.size();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return solve(0,0,text1,text2,dp);
    }
};