class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());  
        vector<int> powr(n);
        powr[0]=1;
        for(int i=1;i<n;i++){
            powr[i]=(powr[i-1]*2) % mod;
        }

        int cnt=0;
        int l=0;
        int r=n-1;

        while(l<=r){
            int sum=nums[l]+nums[r];
            if(sum>target){
                r--;
            }
            else{
                cnt = (cnt + powr[r-l]) % mod;
                l++;
            }

        }
        return cnt % mod;  
    }
};