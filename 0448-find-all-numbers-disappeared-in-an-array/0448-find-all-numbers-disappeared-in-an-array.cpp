class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;

        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};