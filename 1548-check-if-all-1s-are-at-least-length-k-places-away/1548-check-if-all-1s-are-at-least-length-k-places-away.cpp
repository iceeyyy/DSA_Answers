class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len=0;
        bool flg=false;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(flg && len<k) return false; //if first 1 is encountered and the second one is also encountered
                flg=true; //if it is the first one
                len=0; //reset the length
            }
            else if(flg){
                len++;
            }
        }

        return true;
    }
};