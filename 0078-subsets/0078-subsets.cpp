class Solution {
public:
    void subs(int ind,int n,vector<int>& ds, vector<vector<int>>& ans,vector<int>&nums) {
        
        if(ind>=n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        subs(ind+1,n,ds,ans,nums); //taking the element
        ds.pop_back();
        subs(ind+1,n,ds,ans,nums); // not taking the element
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        int n=nums.size();
        subs(0,n,ds,ans,nums);

        return ans;

    }
};