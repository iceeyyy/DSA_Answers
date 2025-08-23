class Solution {
public:
 int minArea(int startRow,int endRow,int startCol,int endCol,vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int minRow=rows;
        int maxRow=-1;
        int maxCol=-1;
        int minCol=cols;

        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
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
    int calculate(vector<vector<int>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();
        int result=INT_MAX;

        for(int rowSplit=1;rowSplit<rows;rowSplit++){
            for(int colSplit=1;colSplit<cols;colSplit++){
                //case1
               int top=minArea(0,rowSplit,0,cols,grid);
               int bottomLeft=minArea(rowSplit,rows,0,colSplit,grid);
               int bottomRight=minArea(rowSplit,rows,colSplit,cols,grid);

               result=min(result,top+bottomLeft+bottomRight);
               //case2
               int topLeft  = minArea(0,rowSplit,0,colSplit,grid);
               int topRight = minArea(0,rowSplit,colSplit,cols,grid);
               int bottom   = minArea(rowSplit,rows,0,cols,grid);

               result=min(result,topLeft+bottom+topRight);

            }
        }

        for(int rowSplit1=1;rowSplit1<rows;rowSplit1++){
            for(int rowSplit2=rowSplit1+1;rowSplit2<rows;rowSplit2++){
                //case3
                int top=minArea(0,rowSplit1,0,cols,grid);
                int mid=minArea(rowSplit1,rowSplit2,0,cols,grid);
                int bottom=minArea(rowSplit2,rows,0,cols,grid);

                result=min(result,top+mid+bottom);
            }
        }
        return result;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int res1=calculate(grid);
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> rotated(cols,vector<int>(rows));
        //rotating the grid
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                rotated[j][rows-i-1]=grid[i][j];
            }
        }
        int res2=calculate(rotated);

        return min(res1,res2);

    }
};