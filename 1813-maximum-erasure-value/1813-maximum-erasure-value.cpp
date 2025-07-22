class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int res=0;
        int sum=0;
        unordered_set<int> st;

        while(j<nums.size()){
            if(!st.count(nums[j])){
                sum+=nums[j];
                res=max(res,sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                while(st.count(nums[j])){
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return res;
    }
};