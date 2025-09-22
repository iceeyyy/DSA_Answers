class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int maxx=-1;
        for(auto it:mp){
            maxx=max(maxx,it.second);
        }

        int ans=0;
        for(auto it:mp){
            if(maxx == it.second){
                ans+=it.second;
            }
        }

        return ans;
        
    }
};