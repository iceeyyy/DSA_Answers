class Solution {
public:
    bool isVowel(char ch){
        char c = tolower(ch);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    string sortVowels(string s) {
        unordered_map<char,int> mp;
        string vowel = "AEIOUaeiou";
        int j = 0;

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                mp[s[i]]++;
            }
        }

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                while(mp[vowel[j]]==0){
                    j++; //move the pointer till we find the char that exists in the string
                }
                s[i]=vowel[j];
                mp[vowel[j]]--; //decreasing the freq of char
            }
        }
        return s;
    }
};