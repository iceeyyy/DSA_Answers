class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        unordered_set<int> st;
        if(n==1) return nums[0];

        int nega=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nega=max(nega,nums[i]);
            } //store the biggest negative number possible
            else if(!st.contains(nums[i])){
                sum+=nums[i];
                st.insert(nums[i]);
            }
        }

        return (sum==0)?nega:sum;  //if sum==0 it means there is no postive number in the input  
    }
};