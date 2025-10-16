class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int r = ((nums[i]%val)+val)%val;
            mp[r]++;
        }
        
        int MEX=0;

        while(mp[MEX%val]){
            mp[MEX%val]--;
            MEX++;
        }

        return MEX;
    }
};