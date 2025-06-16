class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int l=nums[0];
        int ans=-1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<l){
                l=nums[i];
            }
            else if( nums[i]-l !=0 && nums[i]>l){
                ans=max(ans,nums[i]-l);
            }
        }

        return ans;
    }
};