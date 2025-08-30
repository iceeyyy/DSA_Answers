class Solution {
public:
    bool checkValid(vector<vector<int>>& board) {
        unordered_set<string>st;
        int n=board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                string row=string(1,board[i][j])+"_ROW_"+ to_string(i);
                string col=string(1,board[i][j])+"_COL_"+ to_string(j);
                

                if(st.find(row)!=st.end()||st.find(col)!=st.end()) return false;
                st.insert(row);
                st.insert(col);
            }
        }
        return true;
    }
};