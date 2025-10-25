class Solution {
    public int totalMoney(int n) {
        int ans=0;
        int mondayMoney=1;

        while(n>0){
            int money=mondayMoney;
            for(int i=1;i<=Math.min(n,7);i++){
                ans+=money;
                money++;
            }
            n-=7;
            mondayMoney++;
        }

        return ans;


    }
}