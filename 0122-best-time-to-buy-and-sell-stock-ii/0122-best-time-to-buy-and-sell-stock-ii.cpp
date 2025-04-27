class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Tabulation Solution for better space complexity
        int n=prices.size();

        vector<vector<int>> dp(n+1,vector<int> (2,0));
        //base Case
        dp[n][0]=dp[n][1]=0;

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int Profit;

              if(buy){
               //even if we are allowed to buy we have two possibilites we can buy or not
              int Buy=-prices[ind]+dp[ind+1][0];
              int Notbuy=0+dp[ind+1][1];
              Profit=max(Buy,Notbuy);
            }

            else{
               // when we are not allowed to buy we can sell or notSell
              int sell=prices[ind]+dp[ind+1][1];
              int notSell=0+dp[ind+1][0];
              Profit=max(sell,notSell);
            }
            dp[ind][buy]=Profit;
            }
        }


        return dp[0][1];
    }
};