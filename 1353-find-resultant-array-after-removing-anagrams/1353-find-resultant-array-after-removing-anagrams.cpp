class Solution {
public:
    bool isAnagram(string s1,string s2){
        sort(s2.begin(),s2.end());
        sort(s1.begin(),s1.end());

        return s1==s2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for(auto word:words){
            if(!ans.empty() && isAnagram(ans.back(),word)) continue;
            ans.push_back(word);
        }

        return ans;
    }
};