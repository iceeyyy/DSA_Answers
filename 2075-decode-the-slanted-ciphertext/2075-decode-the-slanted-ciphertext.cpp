class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        int columns = len/rows;

        string ans="";

        for(int col=0;col<columns;col++){
            for(int j=col;j<len;j+=(columns+1)){
                ans+=encodedText[j];
            }
        }

        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }

        return ans;
    }
};