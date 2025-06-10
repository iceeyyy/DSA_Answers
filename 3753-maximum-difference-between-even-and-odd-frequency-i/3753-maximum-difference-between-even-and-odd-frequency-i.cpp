class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }
        int odd=0;
        int even=s.length(); //max freq can be length of the input string

        for(auto n:mp){
            if((n.second&1)==1){
                odd=max(odd,n.second);
            }
            else if(n.second!=0){
                even=min(even,n.second);
            }
        }
        return odd-even;
    }
};
