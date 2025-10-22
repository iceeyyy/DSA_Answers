class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;

        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first); //repeating element
        }

        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()) ans.push_back(i); //missing element
        }

        return ans;
    }
};