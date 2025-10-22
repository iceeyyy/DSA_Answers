class Solution {
    public int[] findErrorNums(int[] nums) {

        int n=nums.length;
        HashMap<Integer,Integer> mp=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        int missing=-1;
        int duplicate=-1;

        for(Map.Entry<Integer,Integer> entry: mp.entrySet()){
            if(entry.getValue()>1) duplicate=entry.getKey();
        }

        for(int i=1;i<=n;i++){
            if(!mp.containsKey(i)) missing=i;
        }

        return new int[]{duplicate,missing};
    }
}