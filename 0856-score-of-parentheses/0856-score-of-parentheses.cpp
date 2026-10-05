class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else{
                int x=st.top();
                st.pop();
                int score=(x==0)?1:2*x;

                st.top()+=score;
            }
        }

        return st.top();
    }
};