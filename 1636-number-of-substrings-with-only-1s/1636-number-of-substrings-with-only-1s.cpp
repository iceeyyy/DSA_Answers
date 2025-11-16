class Solution {
public:
    int mod = 1e9+7;
    int numSub(string s) {
        int ans=0;
        int cnt=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                ans=(ans+cnt) % mod;
            }
            if(s[i]=='0'){
                cnt=0;
            }
        }

        return ans;
    }
};