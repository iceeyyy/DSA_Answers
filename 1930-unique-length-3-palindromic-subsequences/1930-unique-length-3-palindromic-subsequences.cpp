class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<pair<int,int>> indices(26,{-1,-1});
        int result=0;

        for(int i=0;i<s.length();i++){
            int ind=s[i]-'a';
            if(indices[ind].first==-1){
                indices[ind].first=i;
            }
            indices[ind].second=i;
        }

        for(int i=0;i<26;i++){

            int left=indices[i].first;
            int right=indices[i].second;

            if(left==-1) continue; //doesn't exist

            unordered_set<char> st;

            for(int j=left+1;j<=right-1;j++){
                st.insert(s[j]);
            }
            result+=st.size();
        }

        return result;
    }
};