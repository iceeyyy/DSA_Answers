class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        int r=0;
        int cnt=0;
        while(l<s.size() && r<t.size()){
             if(s[l]!=t[r]){
                r++;
             }
             else if(s[l]==t[r]){
                l++;
                r++;
                cnt++;
             }
        }
        return (cnt==s.size())?1:0;
    }
};