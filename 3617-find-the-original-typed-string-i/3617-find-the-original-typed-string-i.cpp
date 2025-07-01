class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;

        for(int i=1;i<word.length();i++){
            if(word[i-1]==word[i]) cnt++;
        }
        
        return cnt;
    }
};