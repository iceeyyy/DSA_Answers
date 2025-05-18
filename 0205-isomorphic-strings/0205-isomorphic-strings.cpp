class Solution {
public:
    bool isIsomorphic(string s, string t) {

        //if their length is not equal they can't be isomorphic
        if(s.length()!=t.length()){
            return 0;
        }

        unordered_map<char,char>mp1,mp2;

        for(int i=0;i<s.length();i++){

            if((mp1[s[i]] && mp1[s[i]]!=t[i]) || (mp2[t[i]] && mp2[t[i]]!=s[i])){
                // if the replacement exists and it dosn't corresponds to previously assigned one then return false
                return 0;
            }

            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
            
        }
        return 1;

    }
};