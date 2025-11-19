class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans=original;
        unordered_set<int> st(nums.begin(),nums.end());

        while(st.count(ans)){
            ans=ans*2;
        }

        return ans;
    }
};