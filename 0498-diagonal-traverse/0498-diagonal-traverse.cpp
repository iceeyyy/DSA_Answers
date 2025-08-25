class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        vector<int> ans;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto it:mp){
            if((it.first & 1 )!=1){// reverse the odd keys
                reverse(it.second.begin(),it.second.end());
            }
            for(auto i:it.second){
                ans.push_back(i);
            }
        }
        return ans;
    }
};