class Solution {
public:
    int solve(int i,int j,string s, string t,vector<vector<int>>& dp ){
        //Base Case 1
        if(j>=t.length()){
            //all characters were matched
            return 1;
        }
        //Base Case 2
        if(i>=s.length()){
            // not able to match
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            //considering the element and not considering the element
            return dp[i][j]=solve(i+1,j+1,s,t,dp)+solve(i+1,j,s,t,dp);
        }
        //not matched
        return dp[i][j]=solve(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {

        int n=s.length();
        int m=t.length();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return solve(0,0,s,t,dp);
    }
};