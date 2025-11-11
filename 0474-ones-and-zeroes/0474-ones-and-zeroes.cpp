class Solution {
public:
// memoized solution
    int solve(vector<pair<int,int>>& count,int m,int n,int i,vector<vector<vector<int>>>& dp){
        if(i >= count.size() || ( m==0 && n==0 )) return 0;
        int take = 0;

        if(dp[m][n][i]!=-1) return dp[m][n][i];

        if(count[i].first <= m && count[i].second <= n){
            take += 1+solve(count,m-count[i].first,n-count[i].second,i+1,dp);
        }

        int skip = solve(count,m,n,i+1,dp);

        return dp[m][n][i] = max(take,skip);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N=strs.size();

        vector<pair<int,int>> count(N);
        vector<vector<vector<int>>> dp(101,vector<vector<int>> (101,vector<int> (N+1,-1)));

        for(int i=0;i<N;i++){
            //precomputing count of zeros and ones
            int countZero=0;
            int countOne=0;

            for(auto ch:strs[i]){
                if(ch=='0') countZero++;
                else countOne++;
            }
            count[i]={countZero,countOne};
        }

        return solve(count,m,n,0,dp);
    }
};