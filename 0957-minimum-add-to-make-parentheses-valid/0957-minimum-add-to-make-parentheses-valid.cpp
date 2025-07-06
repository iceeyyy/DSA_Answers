class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();   // only pop if top element is '(' so that it can we be cancelled out
                }
                else{
                    st.push(s[i]); // push the unmathced ')'
                }
            }
        }
        return st.size();
    }
};