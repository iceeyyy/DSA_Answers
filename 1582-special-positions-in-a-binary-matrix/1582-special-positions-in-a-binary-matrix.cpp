class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                bool fl=true;
                if(mat[i][j]==1){
                    for(int k=0;k<mat.size();k++){
                        if(k==i) continue;
                        if(mat[k][j]==1) fl=false;
                    }
                    for(int l=0;l<mat[0].size();l++){
                        if(l==j) continue;
                        if(mat[i][l]==1) fl=false;
                    }
                    if(fl==true) ans++;
                }
            }
        }

        return ans;
    }
};