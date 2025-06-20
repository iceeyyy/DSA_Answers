class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.length();
        int N=0;
        int S=0;
        int W=0;
        int E=0;

        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                N++;
            }
            else if(s[i]=='S'){
                S++;
            }
            else if(s[i]=='W'){
                W++;
            }
            else if(s[i]=='E'){
                E++;
            }
            int steps=i+1;
            int curMD=abs(N-S)+abs(E-W);

            int wastedSteps=steps-curMD;
            int extra=0;

            if(wastedSteps!=0){
                extra = min(2*k,wastedSteps);
            }
            int final=curMD+extra;
            
            ans=max(ans,final);

        }

        return ans;
    }
};