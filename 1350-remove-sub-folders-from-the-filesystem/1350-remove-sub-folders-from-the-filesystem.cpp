class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(),folder.end());

        for(int i=0;i<folder.size();i++){
            string subFolder=folder[i];
            string str=subFolder;
            while(!str.empty()){
                auto pos=str.find_last_of('/');
                str=subFolder.substr(0,pos);
                if(st.find(str)!=st.end()){
                    st.erase(subFolder); //already present
                }
            }
        }

        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};