class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k=0;
        int PrevRun=0;
        int CurRun=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                CurRun++;
            }
            else{
                PrevRun=CurRun;
                CurRun=1;
            }
            k=max(k,CurRun/2);
            k=max(k,min(CurRun,PrevRun));
        }

        return k;
    }
};