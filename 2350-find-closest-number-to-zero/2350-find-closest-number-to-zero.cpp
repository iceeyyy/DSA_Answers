class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int close=nums[0];
        for(int i=1;i<nums.size();i++){
            if(abs(close)>abs(nums[i])){
                close=nums[i];
            }
            if(abs(close)==abs(nums[i])){
                if(close<nums[i]){
                    close=nums[i];
                }
            }
        }
        return close;
    }
};