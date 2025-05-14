class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //memoized solution for better space complexity
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){

            int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;

            for(int j=i;j<min(i+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=maxi*len + dp[j+1];
                maxAns=max(maxAns,sum);
            }

            dp[i]=maxAns;
        }

        return dp[0];
    }
};