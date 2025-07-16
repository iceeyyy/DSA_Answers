class Solution {
    public int maximumLength(int[] nums) {
        int odd=0;
        int even=0;
        int pos=0;

        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==1) odd++;
            else{
                even++;
            }
        }
        pos=Math.max(even,odd);

        int len=1;
        int cur=nums[0]%2;

        for(int i=1;i<nums.length;i++){
            if(nums[i]%2!=cur){
                cur=nums[i]%2;
                len++;
            }
        }
        return Math.max(len,pos);
    }
}