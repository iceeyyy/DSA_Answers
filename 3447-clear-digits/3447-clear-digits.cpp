class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string res="";

        if(s.length()==0) return res;
        for(auto ss:s){
            if(isdigit(ss)){
                st.pop();
            }
            else{
                st.push(ss);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};