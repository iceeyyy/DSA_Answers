class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx=0;
        int l=0;
        int r=0;
        while(r<nums.size()){
            if(nums[r]==1){
                r++;
                maxx=max(maxx,r-l);
            }
            else if(nums[r]==0){
                r++;
                l=r;
            }
        }
        return maxx;
    }
};