class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;

        for(int i=n-3;i>=0;i--){
            if(nums[i] + nums[i+1] > nums[i+2]){
                return nums[i] + nums[i+1] + nums[i+2]; // it will return the largest value as it is sorted 
            }
        }
        return 0;
    }
}