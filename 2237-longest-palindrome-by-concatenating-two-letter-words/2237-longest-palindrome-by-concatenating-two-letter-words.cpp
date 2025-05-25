class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int> mp;
        int len=0;
        //searching for reverse of words
        for(auto word:words){

            string resW = word;
            swap(resW[0],resW[1]);

            if(mp[resW]>0){
                len+=4;
                mp[resW]--;
            }

            else{
                mp[word]++;
            }

        }
        //searching for words with same characters
        for(auto it:mp){

            string Word = it.first;
            int count = it.second;

            if(Word[0] == Word[1] && count>0 ){
                len+=2;
                break;
                //words like aa bb can only be inserted in between
                // this type of words can be only used once 
            }
        }
        return len;
    }
};