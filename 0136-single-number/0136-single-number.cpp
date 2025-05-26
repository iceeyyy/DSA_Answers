class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ele=0;

        for(auto i:nums){
            ele^=i;
        }
        
        return ele;
    }
};