class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        int count=0;
        int prev=Integer.MIN_VALUE;

        for(int i=0;i<nums.length;i++){
            int minVal=nums[i]-k;
            if(prev < minVal){
                prev=minVal;
                count++;
            }
            else if(prev < nums[i]+k){
                prev+=1;
                count++;
            }
        }
        return count;
    }
}