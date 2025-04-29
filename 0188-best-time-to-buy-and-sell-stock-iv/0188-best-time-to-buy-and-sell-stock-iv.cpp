class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //Tabulized Solution for better space complexity

        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int K=1;K<=k;K++){

                    int Profit=0;

                    if(buy){
                     int buy=-prices[ind]+dp[ind+1][0][K];
                     int notbuy= dp[ind+1][1][K];
                     Profit=max(buy,notbuy);
                    }
        
                    else{
                     int sell=prices[ind]+dp[ind+1][1][K-1];
                     int notsell=dp[ind+1][0][K];
                     Profit=max(sell,notsell);
                    }
                    dp[ind][buy][K]=Profit;
                }
            }
        }
        return dp[0][1][k];
    }
};