class Solution {
    public int numberOfBeams(String[] bank) {
        int ans=0;
        int prev=0;

        for(int i=0;i<bank.length;i++){
            int cur=0;
            for(char ch:bank[i].toCharArray()){
                if(ch=='1') cur++;
            }
            if(cur>0){
                ans+=prev*cur;
                prev=cur;
            }
        }

        return ans;
    }
}