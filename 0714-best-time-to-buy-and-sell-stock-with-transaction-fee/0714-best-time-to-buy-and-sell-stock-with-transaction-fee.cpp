class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        //Tabulized Solution for better Space Complexity with space optimization
        int n=prices.size();

        vector<int> ahead(2,0);
        vector<int> cur(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){

                int Profit=0;

                if(buy){
                    int buyy=-prices[ind]+ahead[0];
                    int notbuy=ahead[1];
                    Profit=max(buyy,notbuy);
                }

                else{
                    int sell=prices[ind]-fee+ahead[1];
                    int notSell=ahead[0];
                    Profit=max(sell,notSell);
                }
               cur[buy]=Profit;
            }
            ahead=cur;
        }

        return ahead[1];
    }
};