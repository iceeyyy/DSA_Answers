class Solution {
public:
   int solve(int ind,vector<int>& nums,int & maxSum,vector<int>& dp){
    //memoized solution
    if(ind>=nums.size()){
        return 0;
    }

    if(dp[ind]!=INT_MIN) return dp[ind];

    int l=nums[ind]+solve(ind+1,nums,maxSum,dp); //include the element and move to the next index

    int r=nums[ind];

    maxSum=max(maxSum,max(l,r));

    return dp[ind]=max(l,r);
   }
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();

        int maxSum=nums[0];

        vector<int> dp(n,INT_MIN);

        solve(0,nums,maxSum,dp);

        return maxSum;
    }
};