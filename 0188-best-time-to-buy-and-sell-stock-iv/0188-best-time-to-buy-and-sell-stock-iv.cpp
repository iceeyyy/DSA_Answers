class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //Tabulized Solution for better space complexity
        //with space optimization

        int n=prices.size();

        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int K=1;K<=k;K++){

                    int Profit=0;

                    if(buy){
                     int buy=-prices[ind]+ahead[0][K];
                     int notbuy= ahead[1][K];
                     Profit=max(buy,notbuy);
                    }
        
                    else{
                     int sell=prices[ind]+ahead[1][K-1];
                     int notsell=ahead[0][K];
                     Profit=max(sell,notsell);
                    }
                    cur[buy][K]=Profit;
                }
                ahead=cur;
            }
        }
        return ahead[1][k];
    }
};