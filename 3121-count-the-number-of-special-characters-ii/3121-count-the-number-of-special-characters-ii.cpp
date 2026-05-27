class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        int cnt=0;

        vector<int> smallLet(26,-1);
        vector<int> firstCap(26,-1);

        for(int i=0;i<n;i++){
            if(islower(word[i])){
                smallLet[word[i]-'a']=i;
            }
            else{
                if(firstCap[word[i]-'A']==-1){
                    firstCap[word[i]-'A']=i;
                }
            }
        }
        
        for(int i=0;i<26;i++){
            if(smallLet[i]!=-1 && firstCap[i]!=-1 && smallLet[i]<firstCap[i]) cnt++;
        }

        return cnt;
    }
};