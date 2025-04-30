class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        //Tabulized Solution for better Space Complexity
        int n=prices.size();

        vector<vector<int>> dp(n+1,vector<int> (2,0));

        //Base Case
        for(int i=0;i<2;i++){
            dp[n][i]=0;
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){

                int Profit=0;

                if(buy){
                    int buyy=-prices[ind]+dp[ind+1][0];
                    int notbuy=dp[ind+1][1];
                    Profit=max(buyy,notbuy);
                }

                else{
                    int sell=prices[ind]-fee+dp[ind+1][1];
                    int notSell=dp[ind+1][0];
                    Profit=max(sell,notSell);
                }
               dp[ind][buy]=Profit;
            }
        }

        return dp[0][1];
    }
};