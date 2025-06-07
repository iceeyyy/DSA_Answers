class Solution {
public:
    string clearStars(string s) {

        vector<vector<int>> hash(26);

        for(int i=0;i<s.length();i++){

            if(s[i]=='*'){

                for(int j=0;j<26;j++){
                    if(hash[j].size()>0){
                        s[hash[j].back()]='*'; //marking the right most smallest character as *
                        hash[j].pop_back(); //poping it out from the hash array
                        break;
                    }
                }

            }
            else{
                hash[s[i]-'a'].push_back(i);
            }
        }

        string ans="";
        //removing * from the string to get our answer
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                continue;
            }
            ans+=s[i];
        }

        return ans;
    }
};