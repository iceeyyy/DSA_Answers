class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;

        while(numBottles>=numExchange){
            ans+=numExchange;
            numBottles-=numExchange;

            numBottles++; // got from exchange
            numExchange++; // increased exhcange rate after each exchange
        }

        ans+=numBottles;

        return ans;
    }
};