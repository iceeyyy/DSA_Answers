class Solution {
public:
    int getDist(int x1 ,int y1 ,int x2 ,int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    pair<int,int> getCord(char ch){
        int cur = ch-'A';
        return {cur/6,cur%6};
    }
    int solve(string& word,int i,int x1,int y1,int x2,int y2,vector<vector<vector<vector<vector<int>>>>>& dp){
        if(i>=word.size()){
            return 0;
        }

        if(dp[i][x1+1][y1+1][x2+1][y2+1] != -1) return dp[i][x1+1][y1+1][x2+1][y2+1];

        auto [x,y] = getCord(word[i]);
        if(x1==-1 && y1==-1 && x2==-1 && y2==-1 ){
            //both fingers unused
            return dp[i][x1+1][y1+1][x2+1][y2+1]=solve(word,i+1,x,y,x2,y2,dp);
        }
        //finger 2 not used
        if(x2==-1 && y2==-1){
            int moveF2=solve(word,i+1,x1,y1,x,y,dp);
            int moveF1=getDist(x1,y1,x,y)+solve(word,i+1,x,y,x2,y2,dp);
            return dp[i][x1+1][y1+1][x2+1][y2+1]=min(moveF2,moveF1);
        }
        int moveF1= getDist(x1,y1,x,y)+solve(word,i+1,x,y,x2,y2,dp);
        int moveF2= getDist(x2,y2,x,y)+solve(word,i+1,x1,y1,x,y,dp);

        return dp[i][x1+1][y1+1][x2+1][y2+1]=min(moveF1,moveF2);
    }
    int minimumDistance(string word) {
        int n =word.size();
        vector<vector<vector<vector<vector<int>>>>> dp(n,vector<vector<vector<vector<int>>>>(7,vector<vector<vector<int>>>(
            7,vector<vector<int>>(7,vector<int>(7, -1)))));
        return solve(word,0,-1,-1,-1,-1,dp);
    }
};