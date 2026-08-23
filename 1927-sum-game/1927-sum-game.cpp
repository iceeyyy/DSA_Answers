class Solution {
public:
    bool sumGame(string num) {
        int lSum=0;
        int rSum=0;

        int lQ=0;
        int rQ=0;
        int n=num.length();

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    lQ++;
                }
                else{
                    rQ++;
                }
            }
            else{
                if(i<n/2){
                    lSum+=num[i]-'0';
                }
                else{
                    rSum+=num[i]-'0';
                }
            }
        }

        int totalQ=lQ+rQ;

        if(totalQ%2==1) return true;

        int left=2*lSum+9*lQ;
        int right=2*rSum+9*rQ;

        if(left==right) return false;

        return true;
    }
};