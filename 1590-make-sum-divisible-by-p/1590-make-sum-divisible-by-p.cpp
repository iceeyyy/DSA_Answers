class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;

        for(auto x:nums){
            sum=(sum+x)%p;
        }
        int target=sum%p;

        if(target==0) return 0; //already divisible

        unordered_map<int,int> mp;
        // sum % p, index
        mp[0]=-1;

        int n=nums.size();
        int ans=n;
        int cur=0;

        for(int j=0;j<n;j++){
            cur=(cur+nums[j])%p;
            int remain=(cur-target+p)%p;

            if(mp.find(remain)!=mp.end()){
                int len=j-mp[remain];
                ans=min(ans,len);
            }
            mp[cur]=j;
        }
        return (ans==n)?-1:ans;
    }
};