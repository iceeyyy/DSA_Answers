class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n);

        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        long long result=LONG_MIN;

        for(int start=0;start<k;start++){
            long long currSum=0;
            int i=start;

            while(i<n && i+k-1<n){
                int j=i+k-1;
                long long subSum=prefix[j] - ((i>0)?prefix[i-1]:0);

                currSum=max(subSum,currSum+subSum);
                result=max(result,currSum);
                i+=k; //because we want the size of subaaray to be divisible of k
            }
        }

        return result;
    }
};