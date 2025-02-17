class Solution {
public:
    int build(vector<int>& freq){
        int comb=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                freq[i]--;
                comb+=1+build(freq);
                freq[i]++;
            }
        }
        return comb;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(auto c:tiles){
            freq[c-'A']++;
        }
        return build(freq);
    }
};