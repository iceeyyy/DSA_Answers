class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int count=1<<k;
        unordered_set<string> st;
        for(int i=k;i<=s.length();i++){
            string sub = s.substr(i-k,k);
            if(!st.count(sub)){
                st.insert(sub);
                count--;
            }
            if(count==0) return true;
        }

        return false;
    }
};