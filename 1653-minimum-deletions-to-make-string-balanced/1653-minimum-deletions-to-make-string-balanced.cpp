class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='a'){
                st.pop();
                cnt++;
            }
            else if(s[i]=='b'){
                st.push(s[i]);
            }
        }

        return cnt;
    }
};