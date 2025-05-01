class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);

        //computing the dp array
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
        }
        //return the max value in the array
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};