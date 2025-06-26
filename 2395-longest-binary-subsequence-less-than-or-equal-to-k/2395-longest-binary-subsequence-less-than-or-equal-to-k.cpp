class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int len=0;
        long long power=1; //2**0

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                len++;
            }
            else if(power<=k){
                k-=power;
                len++;
            }
            if(power<=k){
                power<<=1; //increasing the power by 1 every time
            }
        }
        return len;
    }
};