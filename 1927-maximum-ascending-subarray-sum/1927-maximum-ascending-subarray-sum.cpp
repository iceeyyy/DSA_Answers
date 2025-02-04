class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0];
        int maxx=ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans+=nums[i];
            }
            else{
                maxx=max(maxx,ans);
                ans=nums[i];
            }
        }
        return max(ans,maxx);
    }
};