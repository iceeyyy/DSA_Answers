class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int minRow=rows;
        int maxRow=-1;
        int maxCol=-1;
        int minCol=cols;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    minRow=min(minRow,i);
                    maxRow=max(maxRow,i);

                    minCol=min(minCol,j);
                    maxCol=max(maxCol,j);
                }
            }
        }

        int length=maxRow-minRow+1;
        int breadth=maxCol-minCol+1;

        return length*breadth;

    }
};