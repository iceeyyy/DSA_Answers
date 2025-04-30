class Solution {
public:
    int solve(int ind,int buy, int fee,vector<int>& prices,vector<vector<int>>& dp){
        //memoized solution for better time complexity
        //Base Case
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int Profit=0;

        if(buy){
            int buyy=-prices[ind]+solve(ind+1,0,fee,prices,dp);
            int notbuy=solve(ind+1,1,fee,prices,dp);
            Profit=max(buyy,notbuy);
        }

        else{
            int sell=prices[ind]-fee+solve(ind+1,1,fee,prices,dp);
            int notSell=solve(ind+1,0,fee,prices,dp);
            Profit=max(sell,notSell);
        }

        return dp[ind][buy]=Profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));

        return solve(0,1,fee,prices,dp);
    }
};