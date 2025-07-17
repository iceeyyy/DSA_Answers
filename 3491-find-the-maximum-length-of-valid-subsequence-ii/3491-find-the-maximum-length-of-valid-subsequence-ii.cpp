class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(k,vector<int> (n,1));
        int maxSub=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod=(nums[j]+nums[i])%k;

                dp[mod][i]= max(dp[mod][i],1+dp[mod][j]);
                maxSub=max(maxSub,dp[mod][i]);
            }
        }
        return maxSub;
    }
};