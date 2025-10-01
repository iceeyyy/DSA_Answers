class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long ans=0;
        int totalBottles=numBottles;
        ans+=numBottles; // all the bottles are drinkable at first

        while(totalBottles >= numExchange){
            int bottles = totalBottles/numExchange;
            int rem = totalBottles % numExchange;
            totalBottles=bottles;
            if(rem!=0){
                totalBottles+=rem;
            }
            ans += bottles;
        }

        return ans;
    }
};