class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        //if array is pre sorted then 1st elment would be the smallest and n-1 th would be the largest
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};