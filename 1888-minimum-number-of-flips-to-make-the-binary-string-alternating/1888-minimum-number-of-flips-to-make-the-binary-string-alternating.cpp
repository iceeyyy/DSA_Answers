class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s1,s2;

        for(int i=0;i<2*n;i++){
            s1+=(i%2?'1':'0');
            s2+=(i%2?'0':'1');
        }

        int flip1=0;
        int flip2=0;

        int ans=INT_MAX;

        int j=0;
        int i=0;

        while(j<2*n){
            if(s[j%n]!=s1[j]) flip1++;
                
            if(s[j%n]!=s2[j]) flip2++;

            if(j-i+1>n){
                if(s[i%n]!=s1[i]) flip1--;
                if(s[i%n]!=s2[i]) flip2--;
                i++;
            }

            if(j-i+1==n){
                //only consider updating the size if window's size is equal to the string's size
                ans=min({ans,flip1,flip2});
            }
            j++;
        }

        return ans;
    }
};