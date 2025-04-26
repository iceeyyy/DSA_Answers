class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //considering 1st value to be minimum price
        int mini=prices[0];
        int maxProf=0;

        for(int i=1;i<prices.size();i++){
            int Prof=prices[i]-mini;
            maxProf=max(maxProf,Prof);
            mini=min(mini,prices[i]);
        }

        return maxProf;
    }
};