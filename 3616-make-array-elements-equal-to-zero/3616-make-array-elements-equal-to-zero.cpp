class Solution {
public:
    bool isValid(int start,int dir,vector<int> nums){
        int n=nums.size();
        int curr=start;
        int d=dir;

        while(curr>=0 && curr<n){
            if(nums[curr]==0){
                curr+=d; //move-forward
            }
            else if(nums[curr]>0){
                nums[curr]--;
                d=-d; //reverse direction
                curr+=d;
            }
        }

        for(auto i:nums){
            if(i!=0) return false;
        }

        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(isValid(i,1,nums)) cnt++; //right
                if(isValid(i,-1,nums)) cnt++; //left
            }
        }
        return cnt;
    }
};