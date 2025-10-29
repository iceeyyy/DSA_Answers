class Solution {
public:
    bool isValid(string i){
        for(auto it:i){
            if(it=='0') return false;
        }
        return true;
    }
    string binary(int n){
        string bi="";

        while(n){
            int dig=n%2;
            string digit=to_string(dig);
            n/=2;
            bi+=digit;
        }
        reverse(bi.begin(),bi.end());

        return bi;
    }
    int smallestNumber(int n) {

        for(int i=n;i<=1e6;i++){
            string bin=binary(i);
            if(isValid(bin)) return i;
        }
        return -1;
    }
};