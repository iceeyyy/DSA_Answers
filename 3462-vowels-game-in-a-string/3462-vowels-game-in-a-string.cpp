class Solution {
public:
    bool isVowel(char ch){
        char c = tolower(ch);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool doesAliceWin(string s) {
        int count=0;

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])) count++;
        }

        return (count==0)?false:true;
    }
};