class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        long long  good_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i]-i)){
                good_cnt+=mpp[nums[i]-i];
            }
            mpp[nums[i]-i]++;
        }
        long long total_cnt=(nums.size()*(nums.size()-1))/2;
        return total_cnt-good_cnt;
    }
};