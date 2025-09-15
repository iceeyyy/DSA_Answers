class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26,false);

        for(char c:brokenLetters){
            broken[c-'a']=true;
        }

        int count=0;
        bool flag=true;

        for(int i=0;i<=text.size();i++){

            if(i<text.size() && text[i]!=' '){ // if it is a character
                if(broken[text[i]-'a']) flag=false;
            }
            else{ //if it is a space
                if(flag) count++;
                flag=true;
            }
        }

        return count;
    }
};