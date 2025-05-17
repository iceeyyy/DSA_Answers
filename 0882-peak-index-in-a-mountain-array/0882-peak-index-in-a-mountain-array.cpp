class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        vector<int> maxx(n,1);
        int ans=0;
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                ans=i;
            }
        }

        return ans;

    }
};