class Solution {
public:
    void help(int ind,vector<int>&nums,vector<int>& vis,vector<int>& ds,set<vector<int>>& ans){
        if(ds.size()==nums.size()){
            ans.insert(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]==1) continue;
            ds.push_back(nums[i]);
            vis[i]=1;
            help(i+1,nums,vis,ds,ans);
            vis[i]=0;
            ds.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds;
        set<vector<int>> ans;
        vector<int> vis(nums.size(),0);

        help(0,nums,vis,ds,ans);
        vector<vector<int>> anss(ans.begin(),ans.end());

        return anss;
        
    }
};