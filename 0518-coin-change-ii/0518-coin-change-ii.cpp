class Solution {
public:
    int solve(int ind,int amount ,vector<int>& coins,vector<vector<int>>& dp){
        //memozied solution for better time complexity
        int n=coins.size();
    
        if(ind==n){
            if(amount==0){
                return 1;
            }
            return 0;
        }
        //memozation check
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        //if we don't pick the coin we move the next index
        int notPick=solve(ind+1,amount,coins,dp);
        //if we pick the element their are infinite chances of picking up the same coin
        int Pick=0;
        if(coins[ind]<=amount){
            Pick=solve(ind,amount-coins[ind],coins,dp);
        }
        
        return dp[ind][amount]=notPick+Pick;
    }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();

        int total=accumulate(coins.begin(),coins.end(),0);
        //maximum values of sum can be the totalSum of the coins 
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};