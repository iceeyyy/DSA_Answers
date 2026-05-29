class Solution {
public:
    int digitSum(int num){
        int ans=0;
        while(num){
            int digit=num%10;
            num/=10;
            ans+=digit;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        vector<int> res;
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            res.push_back(digitSum(nums[i]));
        }

        for(int i=0;i<res.size();i++){
            ans=min(ans,res[i]);
        }

        return ans;
                                                                                                
    }
};