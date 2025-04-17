class Solution {
public:
    int solve(int ind,int Target,vector<int>& coins,vector<vector<int>>& dp){
        int n=coins.size();
        //Base case
        if(ind==n-1){
            if(Target%coins[ind]==0) return Target/coins[ind];
            //if the combination is possible then return number of coins required for the Target
            else return 1e7;
        }
        //memoization check
        if(dp[ind][Target]!=-1) return dp[ind][Target];

        int notTake=solve(ind+1,Target,coins,dp);
        int take=INT_MAX;

        if(coins[ind]<=Target){
            //we can take 1 coin infinite times that why we stay at the same index even after taking it
            take=1+solve(ind,Target-coins[ind],coins,dp);
        }

        return dp[ind][Target]=min(notTake,take);

    }
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=solve(0,amount,coins,dp);

        if(ans>=1e7) return -1;

        return ans;
    }
};