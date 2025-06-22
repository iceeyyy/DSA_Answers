class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();

        if(n%k!=0){
            //add fill character till length of the string is divisible by k
            while(s.length()%k!=0){
                s+=fill;
            }
        }
        vector<string> ans;
        int div=n/k;

        for(int i=0;i<n;i+=k){
            string ss=s.substr(i,k);
            ans.push_back(ss);
        }

        return ans;
    }
};