class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=0;
        int cnt=0;

        for(int i=1;i<n;i++){
            while(nums[i]-nums[mini]>1){
                mini++; //increment mini till diff is 1
            }
            if(nums[i]-nums[mini]==1) cnt=(max(cnt,(i-mini+1)));
            
        }
        return cnt;
    }
};