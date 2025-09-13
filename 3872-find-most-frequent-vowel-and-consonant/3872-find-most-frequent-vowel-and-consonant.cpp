class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        int n=s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        int vowel=0;
        int consonent=0;

        for(auto it:mp){
            char ch=it.first;
            int freq=it.second;

            if(isVowel(ch)){
                vowel=max(vowel,freq);
            }

            else{
                consonent=max(consonent,freq);
            }
        }

        return vowel+consonent;
    }
};