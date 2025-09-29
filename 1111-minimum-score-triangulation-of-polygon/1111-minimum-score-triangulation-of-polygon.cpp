class Solution {
public:
    int solve(vector<int>& values,int i,int j,vector<vector<int>>& ds){
        if( j-i+1 < 3){
            return 0; //triangilation is not possible
        }
        if(ds[i][j]!=-1) return ds[i][j];

        int res=1e9;

        for(int k=i+1;k<j;k++){
            int wt = solve(values,i,k,ds) + values[i]*values[k]*values[j] + solve(values,k,j,ds);
            //left half + triangulated part + right half
            res=min(res,wt);
        }

        return ds[i][j]=res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> ds(n,vector<int>(n,-1));

        return solve(values,0,n-1,ds);
    }
};