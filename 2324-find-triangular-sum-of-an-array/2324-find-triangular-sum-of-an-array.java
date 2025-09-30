class Solution {
    public int triangularSum(int[] nums) {
        int n=nums.length; 

        for(int sizee=n-1;sizee>=1;sizee--){ //O(N^2)
            for(int i=0;i<sizee;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }

        return nums[0];
    }
}