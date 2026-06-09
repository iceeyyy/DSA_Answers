class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxx = INT_MIN;
        int minn = INT_MAX;

        for(int i=0;i<nums.size();i++){
            maxx=max(maxx,nums[i]);
            minn=min(minn,nums[i]);
        }

        return (long long)(maxx-minn)*k; 
    }
};