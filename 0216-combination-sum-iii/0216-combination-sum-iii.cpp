class Solution {
public:
    void comb3(int ind,int n,int k,vector<int>& ds,vector<vector<int>>& ans){

        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }

        for(int i=ind;i<=9;i++){
            if(i<=n){
                ds.push_back(i);
                comb3(i+1,n-i,k,ds,ans);
                ds.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;

        comb3(1,n,k,ds,ans);
        return ans;
    }
};