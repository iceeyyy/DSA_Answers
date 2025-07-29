class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> setBits(32,-1);

        for(int i=n-1;i>=0;i--){
            int endBit=i;
            for(int j=0;j<32;j++){
                if(!(nums[i] & (1<<j) )){
                    if(setBits[j]!=-1){
                        endBit=max(endBit,setBits[j]);
                    }
                }
                else{
                    setBits[j]=i;
                }
            }
            ans[i]=endBit-i+1;
        }
        return ans;
    }
};