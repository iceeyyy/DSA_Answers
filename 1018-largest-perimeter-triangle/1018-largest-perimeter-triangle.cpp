class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=n-3;i>=0;i--){
            if(nums[i] + nums[i+1] > nums[i+2]){

                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return 0;
    }
};