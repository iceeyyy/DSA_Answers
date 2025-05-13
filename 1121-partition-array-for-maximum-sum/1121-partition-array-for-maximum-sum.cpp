class Solution {
public:
    int solve(int i,vector<int>& arr, int k,vector<int>& dp){
        int n=arr.size();
        if(i==n) return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;

        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=maxi*len + solve(j+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }

        return dp[i]= maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};