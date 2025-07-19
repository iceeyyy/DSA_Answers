class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(),folder.end());

        for(int i=0;i<folder.size();i++){
            string subFolder=folder[i];
            string str=subFolder;
            while(!str.empty()){
                auto pos=str.find_last_of('/'); //returns the last position of the char in a string
                str=subFolder.substr(0,pos);
                if(st.find(str)!=st.end()){
                    st.erase(subFolder); //already present
                    break;
                }
            }
        }

        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};