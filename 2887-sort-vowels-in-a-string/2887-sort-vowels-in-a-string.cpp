class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')?true:false;
    }
    string sortVowels(string s) {
        string temp="";
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(isVowel(tolower(s[i]))){
                temp.push_back(s[i]);
            }
        }

        sort(temp.begin(),temp.end()); //sort the string

        for(int i=0;i<s.length();i++){
            if(isVowel(tolower(s[i]))){
                s[i]=temp[j];
                j++;
            }
        }
        return s;
    }
};