class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        //tabulation solution 
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        
        for(int ind=n-1;ind>=0;ind--){
            for(int prevind=n-1;prevind>=-1;prevind--){

                int notPick=dp[ind+1][prevind+1];
                int Pick=0;
              //if we include prevind==-1 then we can include 1st index
                if(prevind==-1 || nums[prevind]<nums[ind]){
                   Pick=1+dp[ind+1][ind+1];
                }

              dp[ind][prevind+1]=max(notPick,Pick);
            }
        }

        return dp[0][-1+1];
    }
};