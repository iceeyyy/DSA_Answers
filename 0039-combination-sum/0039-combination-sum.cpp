class Solution {
public:
    void combSum(int ind,int target,vector<int>& ds ,vector<vector<int>>& ans,vector<int>& arr){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
                
            ds.push_back(arr[ind]);
                
            combSum(ind,target-arr[ind],ds,ans,arr);

            ds.pop_back();
                
        }
        combSum(ind+1,target,ds,ans,arr);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        combSum(0,target,ds,ans,candidates);

        return ans;
    }
};