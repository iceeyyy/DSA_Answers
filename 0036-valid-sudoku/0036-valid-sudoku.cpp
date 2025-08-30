class Solution {
public:
    bool traverse(vector<vector<char>>& grid,int sr,int er,int sc,int ec){
        unordered_set<char>st;

        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(grid[i][j]=='.') continue;
                if(st.find(grid[i][j])!=st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& grid) {
        //validating rows
        for(int i=0;i<9;i++){
            unordered_set<char>st;
            for(int j=0;j<9;j++){
                if(grid[i][j]=='.')continue;
                if(st.find(grid[i][j])!=st.end()) return false;
                st.insert(grid[i][j]);
            }
        }
        //validating cols
        for(int j=0;j<9;j++){
            unordered_set<char>st;
            for(int i=0;i<9;i++){
                if(grid[i][j]=='.')continue;
                if(st.find(grid[i][j])!=st.end()) return false;
                st.insert(grid[i][j]);
            }
        }
        //validating 3x3
        for(int sr=0;sr<9;sr+=3){
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int ec=sc+2;
                if(!traverse(grid,sr,er,sc,ec)) return false;
            }
        }
        return true;
    }
};