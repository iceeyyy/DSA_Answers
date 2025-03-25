class Solution {
public:
    void subs(int i,vector<int>& ds,vector<vector<int>>& ans,vector<int>& take,vector<int> & nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){

            if(take[i]==1) continue; //dont't take element's if it's already taken

            ds.push_back(nums[i]);
            take[i]=1;
            subs(i,ds,ans,take,nums);
            take[i]=0;
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n=nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int> take(n,0);

        subs(0,ds,ans,take,nums);
    
        return ans;
    }
};