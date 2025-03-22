class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double maxA=0;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxA=sum/k;
        
        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];
            double cal=sum/k;
            maxA=max(maxA,cal);
        }
        return maxA;
    }
};