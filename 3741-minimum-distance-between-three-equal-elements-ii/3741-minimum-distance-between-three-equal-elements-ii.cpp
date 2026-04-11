class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int result = INT_MAX;

        for(int k=0;k<n;k++){
            mp[nums[k]].push_back(k);
            if(mp[nums[k]].size()>=3){
                vector<int> &vec = mp[nums[k]];
                int i=vec[vec.size()-3];
                // int k=vec[vec.size()-1];
                result=min(result,2*(k-i));
            }
        }

        return (result==INT_MAX)?-1:result;
    }
};