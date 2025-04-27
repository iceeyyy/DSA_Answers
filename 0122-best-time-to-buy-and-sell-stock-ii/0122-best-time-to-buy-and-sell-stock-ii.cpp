class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
        //Base Case
        if(ind==prices.size()){
            return 0;
        }
        //memoization check
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int Profit;

        if(buy){
            //even if we are allowed to buy we have to possible we can buy or not
            int Buy=-prices[ind]+solve(ind+1,0,prices,dp);
            int Notbuy=0+solve(ind+1,1,prices,dp);
            Profit=max(Buy,Notbuy);
        }

        else{
            // when we are not allowed to buy we can sell or notSell
            int sell=prices[ind]+solve(ind+1,1,prices,dp);
            int notSell=0+solve(ind+1,0,prices,dp);
            Profit=max(sell,notSell);
        }

        return dp[ind][buy]=Profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int> (2,-1));

        return solve(0,1,prices,dp);
    }
};