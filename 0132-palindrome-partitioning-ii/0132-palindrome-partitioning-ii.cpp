class Solution {
public:
    bool ispalin(int i, int j,string &s){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int solve(int i,string s,vector<int>& dp){

        if(i==s.length()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=INT_MAX;

        for(int j=i;j<s.length();j++){
            
            // only call for next when temp string is palindrome
            if(ispalin(i,j,s)){
                int cost=1+solve(j+1,s,dp);
                ans=min(ans,cost);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        //we need to subtract 1 because our code performs partitioning for the last character as well and then return 0 
        return solve(0,s,dp)-1;
    }
};