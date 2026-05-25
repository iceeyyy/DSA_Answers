class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        int cnt=0;
        vector<int> ans(n,0);
        ans[0]=1;
        
        for(int j=1;j<n;j++){
            if(j-minJump>=0){
                cnt+=ans[j-minJump];
            }
            if(j-maxJump-1>=0){
                cnt-=ans[j-maxJump-1];
            }
            if(cnt>0 && s[j]=='0') ans[j]=1;
        }

        return ans[n-1]>0;
    }
};