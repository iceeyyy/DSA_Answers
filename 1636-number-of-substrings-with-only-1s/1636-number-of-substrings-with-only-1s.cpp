class Solution {
public:
    const long long mod = 1e9 + 7;
    int numSub(string s) {
        long long  cnt=0;
        long long  ans=0;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;

            if(s[i]=='0' && cnt!=0){
                ans = (ans + (cnt * (cnt + 1) / 2) % mod) % mod;
                cnt = 0; // count of 1 to zero
            }

            if(s[i]=='1' && i==n-1){
                ans = (ans + (cnt * (cnt + 1) / 2) % mod) % mod;
            }
        }

        return ans;
    }
};