class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& ds){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }

        if(ds[i][j] !=-1) return ds[i][j];

        int sum1 = triangle[i][j] + solve(i+1,j,triangle,ds);
        int sum2 = triangle[i][j] + solve(i+1,j+1,triangle,ds);

        return ds[i][j]=min(sum1,sum2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> ds(n);

        for(int i=0; i<n; i++) {
            ds[i] = vector<int>(i+1, -1);
        }

        return solve(0,0,triangle,ds);
    }
};