class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans(n,false);
        int mod=0;

        for(int i=0;i<n;i++){
            mod=(mod*2+ nums[i])%5;
            if(mod==0) ans[i]=true;
        }

        return ans;
    }
};