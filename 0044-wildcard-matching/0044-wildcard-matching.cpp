class Solution {
public:
    int solve(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        //Base Case 1
        if(i==s.length() && j<p.length()){
            // if j still has elements to compare it and i has completed all of it's comparisons 
            //all the characters of p must be *
            for(int ii=j;ii<p.length();ii++){
                if(p[ii]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        //Base Case 2
        if(i<s.length() && j==p.length()){
            return 0;
        }
        //Base Case 3
        if(i==s.length() && j==p.length()){
            return 1;
        }
        //memoization Check
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[j]=='?'){
            return dp[i][j]=solve(i+1,j+1,s,p,dp);
        }

        if(p[j]=='*'){
            return dp[i][j]=solve(i+1,j,s,p,dp) || solve(i,j+1,s,p,dp);
        }

        if(s[i]==p[j]){
            return dp[i][j]=solve(i+1,j+1,s,p,dp);
        }

        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {

        int n=s.length();
        int m=p.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        return solve(0,0,s,p,dp);
    }
};