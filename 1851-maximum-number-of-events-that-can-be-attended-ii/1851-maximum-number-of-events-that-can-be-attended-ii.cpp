class Solution {
public:
    int solve(int i,int k,vector<vector<int>>& events,vector<vector<int>>& dp,vector<int>& next){

        if(i>=events.size()|| k==0){
            return 0; //base case
        }

        if(dp[i][k]!=-1) return dp[i][k];
        int skip=solve(i+1,k,events,dp,next);

        int nextt=next[i];  //next possible event to attend if we attend the present event
        int attend=solve(nextt,k-1,events,dp,next) + events[i][2];

        return dp[i][k]=max(skip,attend);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        
        int n=events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        vector<int> next(n);

        for(int i=0;i<n;i++){
            next[i]=upper_bound(events.begin()+i,events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
        }

        return solve(0,k,events,dp,next);
    }
};