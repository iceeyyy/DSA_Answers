class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto i:mp){
            if(i.second==1){
                return i.first;
            }
        }
        return 0;
    }

};