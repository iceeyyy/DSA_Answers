class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> st = new HashSet<>();
        int i=0;
        int j=0;
        int res=0;
        int sum=0;

        while(j<nums.length){
            if(!st.contains(nums[j])){
                sum+=nums[j];
                st.add(nums[j]);
                res=Math.max(res,sum);
                j++;
            }
            else{
                while (st.contains(nums[j])){
                    sum-=nums[i];
                    st.remove(nums[i]);
                    i++;
                }
            }
        }
        return res;
    }
}