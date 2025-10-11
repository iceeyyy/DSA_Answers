class Solution {
public:
    int solve(int start ,vector<int>& energy, int k,vector<int>& dp){
        int n=energy.size();
        if(start>=n) return 0;
        if(dp[start]!=-1) return dp[start];

        int ans=0;
        ans+=energy[start] + solve(start+k,energy,k,dp);

        return dp[start]=ans;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int result=INT_MIN;
        int n=energy.size();
        vector<int> dp(n,-1);

        for(int i=0;i<n;i++){
            int res = solve(i,energy,k,dp);
            result=max(res,result);
        }

        return result;
    }
};