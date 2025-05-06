class Solution {
public:
    int solve(int i,int buy,int cool,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==prices.size()){
            return 0;
        }

        if(dp[i][buy][cool]!=-1) return dp[i][buy][cool];

        int Prof=0;
        if(buy){
            int buy=-prices[i]+solve(i+1,0,0,prices,dp);
            int notBuy=solve(i+1,1,0,prices,dp);
            Prof=max(buy,notBuy);
        }//if there's a cool down period we will skip the index
        else if(cool){
            int skip=solve(i+1,1,0,prices,dp);
            Prof=skip;
        }
        else{
            //there will be a cooldown only if we sell a stock
            int sell=prices[i]+solve(i+1,0,1,prices,dp);
            int notSell=solve(i+1,0,0,prices,dp);
            Prof=max(sell,notSell);
        }
        return dp[i][buy][cool]=Prof;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2,-1)));

        return solve(0,1,0,prices,dp);
    }
};