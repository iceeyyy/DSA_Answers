class Solution {
public:
    string solve(string& curr,int idx, int n,unordered_set<string>& st){
        if(idx==n){
            if(st.count(curr)==0) return curr;
            return "";
        }

        curr.push_back('0');
        string res = solve(curr,idx+1,n,st);
        curr.pop_back();
        if(res!="") return res;

        curr.push_back('1');
        res = solve(curr,idx+1,n,st);
        curr.pop_back();
        if(res!="") return res;

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(),nums.end());
        int n = nums.size();
        string curr = "";
        return solve(curr,0,n,st);
    }
};