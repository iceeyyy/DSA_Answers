class Solution {
public:
   int solve(int ind,vector<int>& nums,int & maxSum){
    
    if(ind>=nums.size()){
        return 0;
    }

    int l=nums[ind]+solve(ind+1,nums,maxSum); //include the element and move to the next index

    int r=nums[ind];

    maxSum=max(maxSum,max(l,r));

    return max(l,r);
   }
    int maxSubArray(vector<int>& nums) {

        int maxSum=nums[0];
        solve(0,nums,maxSum);
        return maxSum;
    }
};