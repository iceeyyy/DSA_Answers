class Solution {
public:
    int M=1e9+7;
    int solve(int n,vector<int>&dp,vector<int>&prev){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int total=(2*solve(n-1,dp,prev))%M;

        if(prev[n]!=0){
            int duplicates=solve(prev[n]-1,dp,prev);
            total=(total-duplicates+M)%M;
        }

        return dp[n]=total;

    }
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        vector<int>prev(n+1,0);
        vector<int>lastSeen(26,0);

        for(int i=1;i<=n;i++){
            int idx=s[i-1]-'a';
            prev[i]=lastSeen[idx];
            lastSeen[idx]=i;
        }

        return (solve(n,dp,prev)-1+M)%M;

    }
};