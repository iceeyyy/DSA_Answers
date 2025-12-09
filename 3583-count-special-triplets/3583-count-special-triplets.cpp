class Solution {
public:
    int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> mp_left;
        unordered_map<int,int> mp_right;
        int ans=0;

        for(auto num:nums){
            mp_right[num]++;
        }

        for(auto num:nums){
            mp_right[num]--;

            int left=mp_left[num*2];
            int right=mp_right[num*2];

            ans = (ans+(1LL * left * right))%mod;
            mp_left[num]++;
        }
        return ans;
    }
};