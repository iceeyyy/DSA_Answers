class Solution {
public:
    int solve(int i,vector<int>& cost,vector<int>& dp){
        //memoized solution for better time complexity
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        //becuase we can either pick move 1 index ahead or 2index ahead
        int firstStep=cost[i]+solve(i+1,cost,dp);
        int secondStep=cost[i]+solve(i+2,cost,dp);

        return dp[i]=min(firstStep,secondStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size(),-1);
        //because we can either start from 0 th index or 1st index
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};