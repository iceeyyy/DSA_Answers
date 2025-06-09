class Solution {
public:
    void solve(int cur,int n,vector<int>& ans){
        if(cur>n) return;

        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            solve(cur*10+i,n,ans);
        }
    
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};