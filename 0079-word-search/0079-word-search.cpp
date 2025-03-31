class Solution {
public:
    bool dfs(int i,int j,int ind,string word,vector<vector<char>>& board){
        if(ind==word.size()) return true; //it will happen if the word is present

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() )  return false;  // we need to return false if the row or col is out of bonds 

        char t=board[i][j];
        
        if(t==word[ind]){
            board[i][j]='.';  //mark it as visited so our recursion dosen't comes back to it
            if(dfs(i+1,j,ind+1,word,board)==true) return true;  //checking for down cell
            if(dfs(i,j+1,ind+1,word,board)==true) return true;  //checking for right cell
            if(dfs(i-1,j,ind+1,word,board)==true) return true; //checking for top cell
            if(dfs(i,j-1,ind+1,word,board)==true) return true; //checking for left cell
            board[i][j]=t;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(i,j,0,word,board)) return true;
            }
        }

        return false;
    }
};