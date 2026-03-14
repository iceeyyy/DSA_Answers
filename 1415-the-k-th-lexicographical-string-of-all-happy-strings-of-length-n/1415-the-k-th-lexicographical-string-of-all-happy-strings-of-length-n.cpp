class Solution {
public:
    void solve(string cur,vector<string>& res,int n){
        if(cur.length()==n){
            res.push_back(cur);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!cur.empty() && cur.back()==ch) continue;
            cur.push_back(ch);
            solve(cur,res,n);
            cur.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        solve("",res,n);

        if(res.size()<k){
            return "";
        }

        return res[k-1];
    }
};