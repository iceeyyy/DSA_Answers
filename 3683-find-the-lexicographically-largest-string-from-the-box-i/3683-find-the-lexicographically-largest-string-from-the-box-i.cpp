class Solution {
public:
    string answerString(string word, int numFriends) {
        //Edge Case
        if(numFriends==1) return word;

        int len=word.size();
        int longest=len-(numFriends-1);
        string ans;

        for(int i=0;i<len;i++){
            int possible=min(longest,len-i);
            //we want the lexograpically largest string
            ans=max(ans,word.substr(i,possible));
        }

        return ans;

    }
};