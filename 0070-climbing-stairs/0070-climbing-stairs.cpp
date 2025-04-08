class Solution {
public:
    int climbStairs(int n) {
        //space optimized solution
        //only last two values are required to compute the curr element so we just use two vairable instead of an array
        //after each ieration they change their places prev2=prev && prev=cur
        //at last we need to return the prev because the required answer would be stored in it
        int prev2=1;
        int prev=1;

        for(int i=2;i<=n;i++){
            int cur=prev2+prev;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};