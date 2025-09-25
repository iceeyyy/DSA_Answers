class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> ds(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            ds[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){

                int sum1 = triangle[i][j] + ds[i+1][j];
                int sum2 = triangle[i][j] + ds[i+1][j+1];

                ds[i][j]=min(sum1,sum2);
            }
        }

        return ds[0][0];
    }
};