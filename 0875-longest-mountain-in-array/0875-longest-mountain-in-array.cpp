class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //implement bitonic thought process
        int n=arr.size();
        if (n < 3) return 0;
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);

        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                dp1[i]=1+dp1[i-1];
            }
        }

        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                //must be greater than it's previous 
                dp2[i]=1+dp2[i+1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                ans=max(ans,dp1[i]+dp2[i]-1);
            }
        }

        return ans >= 3 ? ans :0;
    }
};