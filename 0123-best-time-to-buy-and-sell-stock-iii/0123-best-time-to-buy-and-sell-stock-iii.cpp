class Solution {
public:
    int solve(int ind,int buy,int transactions,vector<int>& prices,vector<vector<vector<int>>>& dp){
        //memoized solotion
        //Base Case we can do anything if the we performed all transcations
        if(ind==prices.size()|| transactions==0){
            return 0;
        }

        if(dp[ind][buy][transactions]!=-1) return dp[ind][buy][transactions];
        
        int Profit=0;

        if(buy){
        int Buy=-prices[ind]+solve(ind+1,0,transactions,prices,dp);
            int Notbuy=0+solve(ind+1,1,transactions,prices,dp);
            Profit=max(Buy,Notbuy);
        }
        else{
            // when we are not allowed to buy we can sell or notSell
            // a transaction would be considered completed if we sell
            int sell=prices[ind]+solve(ind+1,1,transactions-1,prices,dp);
            int notSell=0+solve(ind+1,0,transactions,prices,dp);
            Profit=max(sell,notSell);
        }
            return dp[ind][buy][transactions]=Profit;
    }
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,-1)));
        
        return solve(0,1,2,prices,dp);
    }
};