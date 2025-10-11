class Solution {
public:
    typedef long long ll;
    ll solve(ll i,vector<ll>& nums,unordered_map<ll,ll>& mp,vector<ll>& dp){
        //memoized solution for better time complexity
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        ll notTake = solve(i+1,nums,mp,dp);
        ll j=lower_bound(nums.begin()+i+1,nums.end(),nums[i]+3) - nums.begin(); //for finding next valid index
        ll take = nums[i]*mp[nums[i]] + solve(j,nums,mp,dp);

        return dp[i]=max(notTake,take);
    }
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll,ll>mp;

        for(auto powers:power){
            mp[powers]++; //storing frequencies
        }
        vector<ll> nums(mp.size());

        for(auto it:mp){
            nums.push_back(it.first); // storing unique elements
        }
        //sort the input
        sort(nums.begin(),nums.end());
        vector<ll> dp(nums.size() + 1,-1);
        return solve(0,nums,mp,dp);
    }
};