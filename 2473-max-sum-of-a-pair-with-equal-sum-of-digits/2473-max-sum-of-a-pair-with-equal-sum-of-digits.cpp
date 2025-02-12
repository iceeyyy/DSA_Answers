class Solution {
public:
    int digitsum(int val){
        int sum=0;
        while(val){
            int dig=val%10;
            sum+=dig;
            val/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxsum=-1;

        for(auto ele:nums){
            int digit_sum=digitsum(ele);
            if(mpp.count(digit_sum)){
                maxsum=max(maxsum,ele+mpp[digit_sum]);
                if(mpp[digit_sum]<ele){
                    mpp[digit_sum]=ele;
                }
            }
            else{
                mpp[digit_sum]=ele;
            }
        }
        return maxsum;
    }
};