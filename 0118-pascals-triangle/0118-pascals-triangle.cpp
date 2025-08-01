class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for(int i=0;i<numRows;i++){
            r[i].assign(i+1,1);
            for(int j=1;j<i;j++){
                r[i][j]=r[i-1][j-1]+r[i-1][j];
            }
        }
        return r;
    };
};