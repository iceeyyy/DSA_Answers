class Solution {
public:
    int solve(int ind,int sum,int target,vector<int>& nums){
        if(ind>=nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        int pos=nums[ind]+solve(ind+1,sum+nums[ind],target,nums);
        int neg=-nums[ind]+solve(ind+1,sum-nums[ind],target,nums);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,target,nums);
    }
};