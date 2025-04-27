class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Tabulation Solution with space optimization
        int n=prices.size();

        vector<int> prev(2,0);
        vector<int> cur(2,0);
        
        //base Case
        prev[0]=prev[1]=0;

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int Profit;

              if(buy){
               //even if we are allowed to buy we have two possibilites we can buy or not
              int Buy=-prices[ind]+prev[0];
              int Notbuy=0+prev[1];
              Profit=max(Buy,Notbuy);
            }

            else{
               // when we are not allowed to buy we can sell or notSell
              int sell=prices[ind]+prev[1];
              int notSell=0+prev[0];
              Profit=max(sell,notSell);
            }
            cur[buy]=Profit;
            }
            prev=cur;
        }


        return prev[1];
    }
};