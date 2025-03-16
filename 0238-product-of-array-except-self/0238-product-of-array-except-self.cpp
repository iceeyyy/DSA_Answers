class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int leftProd=1;
        int rightProd=1;
        //calculating left array
        for(int i=0;i<n;i++){
            ans[i]=leftProd;
            leftProd*=nums[i];
        }
        //calculating right array and the resultant array by multiplying left[i] and right[i]
        for(int j=n-1;j>=0;j--){
            ans[j]*=rightProd;
            rightProd*=nums[j];
        }
        return ans;
    }
};