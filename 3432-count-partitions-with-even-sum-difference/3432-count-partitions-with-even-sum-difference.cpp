class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);

        int count=0;
        prefix[0]=nums[0];
        int sum=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            sum+=nums[i];
        }

        for(int i=0;i<n-1;i++){
            int left=prefix[i];
            int right=sum-prefix[i];
            if(abs(left-right)%2==0) count++;
        }

        return count;

    }
};