class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min_val=nums[0];
        int subs=1;

        for(int i=1;i<nums.size();i++){
            if( nums[i]-min_val > k){
                min_val=nums[i];
                subs++;
            }
        }
        return subs;
    }
};