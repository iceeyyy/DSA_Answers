class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        int mini=INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1] +solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        //computing size before adding 0 and n
        int c=cuts.size();
        //insert at the start of the array
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        //sort the cuts array
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        return solve(1,c,cuts,dp);
    }
};