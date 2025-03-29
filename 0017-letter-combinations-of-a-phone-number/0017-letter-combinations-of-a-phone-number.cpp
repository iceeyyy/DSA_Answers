class Solution {
public:
    void solve(int i,string & s,vector<string>& ans,unordered_map<char,string>& mp,string digits){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }

        string letters=mp[digits[i]];

        for(auto letter:letters){
            s.push_back(letter);
            solve(i+1,s,ans,mp,digits);
            s.pop_back(); // we need to pop the element out after the function call so that we can take another element
        }

    }
    vector<string> letterCombinations(string digits) {

        
        //creating a dictionary to get to know  about all the possible letters for a digit
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        vector<string> ans;
        string s="";
        if(digits=="") return ans;
        solve(0,s,ans,mp,digits);

        return ans;
    }
};