class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int monMoney=1;

        while(n>0){
            int money=monMoney;
            for(int i=1;i<=min(n,7);i++){
                ans+=money;
                money++;
            }
            n-=7;
            monMoney++;
        }

        return ans;
    }
};