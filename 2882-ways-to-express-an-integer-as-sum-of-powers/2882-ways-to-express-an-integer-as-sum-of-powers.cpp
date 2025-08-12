class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int sum , int n ,int x,vector<vector<int>>& ds){
        if(sum>n){
            return 0;
        }
        if(sum==n){
            return 1;
        }
        if (pow(i, x) > n){
            return 0;
        }

        if(ds[i][sum]!=-1) return ds[i][sum];

        long long dig = pow(i,x);
         long long take = (solve(i+1,sum+dig,n,x,ds)) %mod;
        long long notTake = (solve(i+1,sum,n,x,ds)) %mod;

        return ds[i][sum] = (take+notTake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> ds(n+1,vector<int>(n+1,-1));
        return solve(1,0,n,x,ds);
    }
};