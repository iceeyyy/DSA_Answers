class Solution {
public:
    bool hasSameDigits(string s) {
        
    
        while(s.length()!=2){
            string ss="";
            for(int i=1;i<s.length();i++){
                int a = s[i-1] - '0';
                int b = s[i] - '0';
                int res = (a+b)%10;
                ss+=to_string(res);
            }
            s=ss;
        }

        return s[0]==s[1];
    }
};