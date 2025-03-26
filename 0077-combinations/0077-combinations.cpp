class Solution {
public:
    void comb(int start,int n,vector<int>& ds,vector<vector<int>>& ans,int k){
        if(k==0){
            ans.push_back(ds);
            return;
        }
        if(start>n) return; //we should stop the recursion if start's value exceeds n's range

        ds.push_back(start); //taking the elment
        comb(start+1,n,ds,ans,k-1);
        ds.pop_back(); //not taking the element
        comb(start+1,n,ds,ans,k);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>ds;
        
        vector<vector<int>> ans;

        comb(1,n,ds,ans,k);


        return ans;
    }
};