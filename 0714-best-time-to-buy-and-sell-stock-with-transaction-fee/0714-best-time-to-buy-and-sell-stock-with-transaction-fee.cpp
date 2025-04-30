class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        //Tabulized Solution for better Space Complexity with most possible space optimization
        int n=prices.size();

        int ahead0=0;
        int ahead1=0;
        int cur0;
        int cur1;

        for(int ind=n-1;ind>=0;ind--){

            int buyy=-prices[ind]+ahead0;
            int notbuy=ahead1;
            cur1=max(buyy,notbuy);

            int sell=prices[ind]-fee+ahead1;
            int notSell=ahead0;
            cur0=max(sell,notSell);

            ahead0=cur0;
            ahead1=cur1;
        }

        return ahead1;
    }
};