class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i=0;
        int j=1;
        int cnt=0;
        int n=nums.size();

        while(j+1<n){
            if(nums[i]==nums[j]) continue;
            if((nums[i]<nums[j] && nums[j]>nums[j+1])|| (nums[i]>nums[j] && nums[j]<nums[j+1])){
                i=j;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};