class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZero=0;
        int ans=0;
        int i=0;
        int n=nums.size();

        for(int j=0;j<n;j++){
            if(nums[j]==0) countZero++;
            while(countZero>1){
                if(nums[i]==0) countZero--;
                i++;
            }
            ans=max(ans,j-i);
        }
        
        return (ans==n)?ans-1:ans;
    }
};