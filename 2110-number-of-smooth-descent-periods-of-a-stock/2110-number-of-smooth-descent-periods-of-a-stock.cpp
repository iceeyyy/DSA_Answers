class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int cnt=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1) cnt++;
            else cnt=1;
            ans+=cnt;
        }
        return ans;
    }
};