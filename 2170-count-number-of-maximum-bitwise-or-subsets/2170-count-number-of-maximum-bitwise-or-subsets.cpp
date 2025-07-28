class Solution {
public:
    int solve(int i,int OR,int maxOr ,vector<int> &nums){
        if(i==nums.size()){
            if(OR==maxOr){
                return 1;
            }
            return 0;
        }
        int take=0;
        int notTake=0;
        
        take+=solve(i+1,OR|nums[i],maxOr,nums);
        notTake+=solve(i+1,OR,maxOr,nums);
        

        return take+notTake;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            maxOr |=nums[i];
        }
        return solve(0,0,maxOr,nums);
    }
};