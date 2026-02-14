class Solution {
public:
    double solve(int i,int j,int poured,vector<vector<double>>& dp){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        if(i==0 && j==0) return poured;

        if(dp[i][j]!=-1) return dp[i][j];

        double left_up = (solve(i-1,j-1,poured,dp)-1)/2.0;
        double right_up = (solve(i-1,j,poured,dp)-1)/2.0;

        if(left_up<0) left_up=0;
        if(right_up<0) right_up=0;

        return dp[i][j]=left_up+right_up;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_glass+1,-1.0));

        return min(1.0,solve(query_row,query_glass,poured,dp));
    }
};