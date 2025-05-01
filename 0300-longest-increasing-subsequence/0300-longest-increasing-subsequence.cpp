class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        //tabulation solution  with space otpimization
        int n=nums.size();
        
        vector<int> prev(n+1,0);
        vector<int> cur(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prevind=n-1;prevind>=-1;prevind--){

                int notPick=prev[prevind+1];
                int Pick=0;
              //if we include prevind==-1 then we can include 1st index
                if(prevind==-1 || nums[prevind]<nums[ind]){
                   Pick=1+prev[ind+1];
                }

              cur[prevind+1]=max(notPick,Pick);
            }
            prev=cur;
        }

        return prev[-1+1];
    }
};