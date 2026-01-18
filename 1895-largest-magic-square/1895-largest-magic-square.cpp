class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rowCumSum(n,vector<int> (m));
        for(int i=0;i<n;i++){
            rowCumSum[i][0] = grid[i][0];
            for(int j=1;j<m;j++){
                rowCumSum[i][j]=rowCumSum[i][j-1] + grid[i][j];
            }
        }

        vector<vector<int>> colCumSum(n,vector<int> (m));
        for(int j=0;j<m;j++){
            colCumSum[0][j]=grid[0][j];
            for(int i=1;i<n;i++){
                colCumSum[i][j] = colCumSum[i-1][j] + grid[i][j];
            }
        }

        for(int side=min(n,m);side>=2;side--){

            for(int i=0;i+side-1<n;i++){

                for(int j=0;j+side-1<m;j++){

                    int targetSum=rowCumSum[i][j+side-1]- (j>0 ? rowCumSum[i][j-1]:0);

                    bool allSame=true;
                    for(int r=i+1;r<i+side;r++){
                        int rowSum=rowCumSum[r][j+side-1]- (j>0 ? rowCumSum[r][j-1]:0);
                        if(rowSum!=targetSum){
                            allSame=false;
                            break;
                        }
                    }
                    if(!allSame) continue;

                    //check cols
                    for(int t=j;t<j+side;t++){
                        int colSum=colCumSum[i+side-1][t]-(i>0?colCumSum[i-1][t]:0);
                        if(colSum!=targetSum){
                            allSame=false;
                            break;
                        }
                    }
                    if(!allSame) continue;
                    //check for diagnols

                    int diag=0;
                    int antiDiag=0;
                    for(int k=0;k<side;k++){
                        diag+=grid[i+k][j+k];
                        antiDiag+=grid[i+k][j+side-1-k];
                    }
                    if(diag==targetSum && antiDiag==targetSum) return side;
                }
            }
        }

        return 1;
    }
};