class Solution {
public:
    int solve(int i,int d,vector<int>& arr,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int result=1;
        int n=arr.size();
        //left
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j]>=arr[i]) break;
            result=max(result,1+solve(j,d,arr,dp));
        }
        //right
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i]) break;
            result=max(result,1+solve(j,d,arr,dp));
        }
        return dp[i]=result;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int result=1;
        vector<int> dp(n,-1);

        for(int i=0;i<n;i++){
            result=max(result,solve(i,d,arr,dp));
        }
        return result;
    }
};