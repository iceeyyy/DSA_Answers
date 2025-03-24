class Solution {
public:
void comb(int ind,int target,vector<int>& ds,vector<vector<int>>& ans,vector<int> & arr){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind ;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue; //skip if the element is same because we want to avoid duplicates
        if(arr[i]>target) break; //can't pick if it's greater than target value

        ds.push_back(arr[i]);
        comb(i+1,target-arr[i],ds,ans,arr);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        comb(0,target,ds,ans,candidates);
        return ans;
    }
};