class Solution {
public:
    string replaceVowel(string &word){
        string res=word;
        for(auto &c:res){
            if(c=='a'|| c=='e'|| c=='i'|| c=='o'||c=='u'){
                c='*';
            }
        }
        return res;
    }
    string toLower(string &word){
        string res=word;
        for(auto &c:res){
            c=tolower(c);
        }
        return res;
    }
    string checkAns(string &query,unordered_set<string>& st,unordered_map<string,string>& caseMap,unordered_map<string,string>& vowelMap){
        if(st.count(query)){
            return query;
        }

        string lowercase = toLower(query);
        if(caseMap.count(lowercase)){
            return caseMap[lowercase];   //lower check
        }

        string vowelcase = replaceVowel(lowercase);
        if(vowelMap.count(vowelcase)){
            return vowelMap[vowelcase];   //vowel check
        }
        return ""; //not found
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> st;
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;
        vector<string> result;

        for(auto word:wordlist){
            st.insert(word); //insert for exact word checking

            string Lowercase = toLower(word);
            if(caseMap.find(Lowercase)==caseMap.end()){ //for lower check
                caseMap[Lowercase]=word;
            }

            string vowelcase = replaceVowel(Lowercase);
            if(vowelMap.find(vowelcase)==caseMap.end()){
                vowelMap[vowelcase]=word;  // for vowel error
            }
        }

        for(auto it:queries){
            string ans = checkAns(it,st,caseMap,vowelMap);
            result.push_back(ans);
        }

        return result;
    }
};