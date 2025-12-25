class Solution {
public:
    int beautySum(string s) {
        int ans=0;

        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it:mp){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                ans+=maxi-mini;
            }
        }

        return ans;
    }
};