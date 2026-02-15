class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length()-1;
        int m=b.length()-1;

        int sum=0;
        int carry=0;
        string res="";

        while(m>=0 || n>=0){
            sum=carry;
            if(n>=0){
                sum+=a[n]-'0';
                n--;
            }
            if(m>=0){
                sum+=b[m]-'0';
                m--;
            }
            res+=(sum%2==0)?"0":"1";
            carry=sum/2;
        }

        if(carry==1){
            res+="1";
        }
        reverse(res.begin(),res.end());

        return res;
    }
};