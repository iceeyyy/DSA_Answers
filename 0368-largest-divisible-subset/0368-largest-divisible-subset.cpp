class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=INT_MIN;
        int lastIndex=0;

        sort(nums.begin(),nums.end());

        //if we sort the input array the problem is converted into longest Divisible Subset 
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){

                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }

            }
            //for storing the lastIndex
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }

        vector<int> temp;
        //it will insert the last element
        temp.push_back(nums[lastIndex]);

        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        //we need to reverse the temp vector because the subset we stored starts from end 
        reverse(temp.begin(),temp.end());

        return temp;
    }
};