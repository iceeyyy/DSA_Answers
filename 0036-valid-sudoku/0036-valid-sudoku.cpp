class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string row=string(1,board[i][j])+"_ROW_"+ to_string(i);
                string col=string(1,board[i][j])+"_COL_"+ to_string(j);
                string box=string(1,board[i][j])+"_BOX_"+ to_string(i/3) + "_" + to_string(j/3);

                if(st.find(row)!=st.end()||st.find(col)!=st.end()||st.find(box)!=st.end()) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};