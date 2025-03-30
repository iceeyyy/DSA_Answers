class Solution {
public:
    
    bool ispalin(string ss,int start,int end){
        //function for checking whether a string is palindrome or not
        while(start<end){
            if(ss[start++]!=ss[end--]) return false;
        }
        return true;
    }
    void help(int ind,string& s,vector<vector<string>>& ans,vector<string>& ds){
        //base case if ind reaches the end eg. aa -> a|a| last bar represents the last partition possible for checking the last char to be a palindrome or not
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalin(s,ind,i)){
                //only consider it a substring if it is palindrome
                ds.push_back(s.substr(ind,i-ind+1));
                help(i+1,s,ans,ds);
                ds.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        help(0,s,ans,ds);
        return ans;
    }
};