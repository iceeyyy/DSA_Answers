class Solution {
public:
    string reverseWords(string s) {
        //step: 1 remove the whitespaces from behind and front of the text
        int i = 0, j = s.length() - 1;
        while (i <= j && s[i] == ' ') i++; // remove leading spaces
        while (j >= i && s[j] == ' ') j--; // remove trailing spaces

        s = s.substr(i, j - i + 1);

        //step: 2 insert tokens in the stack and pop them out
        stack<string> st;
        stringstream ss(s);
        string token;

        while(getline(ss,token,' ')){
           if(!token.empty())  st.push(token);
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top()+" "; // adds whitespace after every word 
            st.pop();
        }

        if(!ans.empty()) ans.pop_back(); //remove the extra space

        return ans;
    }
};