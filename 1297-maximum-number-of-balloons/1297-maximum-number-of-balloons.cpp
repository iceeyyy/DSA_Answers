class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        
        for(auto i:text){
            mp[i]++;
        }
        // if any value if 0 then ballon is not possible 
        // l and O min freq is 2 so it is divided by 2
        return min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
    }
};