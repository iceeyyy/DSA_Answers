class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(auto ch:stones){
            mp[ch]++; 
        }
        int cnt=0;
        for(int i=0;i<jewels.size();i++){
            for(auto it:mp){
                if(it.first==jewels[i]){
                    cnt+=it.second;
                }
            }
        }
        return cnt;
    }
};