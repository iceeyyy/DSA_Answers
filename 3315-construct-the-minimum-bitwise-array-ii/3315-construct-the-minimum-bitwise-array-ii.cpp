class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                res.push_back(-1);
                continue;
            }
            bool found=false;
            for(int j=1;j<32;j++){
                if((nums[i] & (1<<j))>0){
                    continue;
                }
                int prev = j-1;
                int x=(nums[i]^(1<<(prev)));
                res.push_back(x);
                found=true;
                break;
            }
            if(found==false) res.push_back(-1); // not found
        }
        return res;
    }
};