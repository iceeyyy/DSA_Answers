class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        //computing the dp array
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){

                if(nums[prev]<nums[i] && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }

                else if(nums[prev]<nums[i] && dp[prev]+1 ==dp[i]){
                    cnt[i]+=cnt[prev];
                }
            }
            
            maxi=max(maxi,dp[i]);
        }
    
        int nos=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]){
                nos+=cnt[i];
            }
        }
        return nos;
    }
};