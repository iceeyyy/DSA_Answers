class Solution {
public:
    int maxDepth(string s) {

        int ans=0;
        int depth=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
                ans=max(ans,depth);
            }
            else if(s[i]==')'){
                depth--;
            }
        }
        return ans;
    }
};