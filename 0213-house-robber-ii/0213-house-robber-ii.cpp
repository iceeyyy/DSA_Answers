class Solution {
public:
    int help(vector<int>& nums){
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=prev2;
            }
            int notPick=0+prev;
            int cur=max(pick,notPick);
            prev2=prev;
            prev=cur;
        }
        return prev;
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        //we can't take 1st and last element together
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            //array excluding 1st element
            if(i!=0) temp1.push_back(nums[i]);
            //array exculding last element
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(help(temp1),help(temp2));
    }
};