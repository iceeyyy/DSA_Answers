class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int min1=INT_MAX;
        int min2=INT_MAX;

        for(int i=1;i<nums.size();i++){
            if(min1>nums[i]){
                min2=min1;
                min1=nums[i];
            }
            else if(min2>nums[i]){
                min2=nums[i];
            }
        }
        return ans+min1+min2;
    }
};