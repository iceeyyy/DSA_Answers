class Solution {
public:
    int solve(int ind,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp ){
        //mempized solution for better time complexity

        //Base Case
        if(ind==prices.size()|| k==0){
            return 0;
        }

        if( dp[ind][buy][k] != -1) return dp[ind][buy][k];

        int Profit=0;

        if(buy){
            int buy=-prices[ind]+solve(ind+1,0,k,prices,dp);
            int notbuy= solve(ind+1,1,k,prices,dp);
            Profit=max(buy,notbuy);
        }
        
        else{
            int sell=prices[ind]+solve(ind+1,1,k-1,prices,dp);
            int notsell=solve(ind+1,0,k,prices,dp);
            Profit=max(sell,notsell);
        }
        return dp[ind][buy][k]=Profit;

    }
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,-1)));

        return solve(0,1,k,prices,dp);
    }
};