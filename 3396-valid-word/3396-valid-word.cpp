class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;

        bool hasvowel=false;
        bool hascons=false;

        for(char c:word){
            if(!isalnum(c)) return false;
            if(isalpha(c)){
                char words=tolower(c);
                if(words=='a'||words=='e'||words=='i'||words=='o'||words=='u'){
                    hasvowel=true;
                }
                else{
                    hascons=true;
                }
            }
        }
        return (hasvowel && hascons)?1:0;
    }
};