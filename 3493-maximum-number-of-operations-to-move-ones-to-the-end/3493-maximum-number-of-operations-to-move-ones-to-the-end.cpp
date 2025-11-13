class Solution {
public:
    int maxOperations(string s) {
        // number of operations = number of 1's before 0 
        int count1=0;
        int ans=0;
        int i=0;
        int n=s.length();

        while(i<n){
            if(s[i]=='0'){
                ans+=count1;
                while(i<n && s[i]!='1'){
                    i++;
                }
            }
            if(s[i]=='1'){
                count1++; //increase the counter and move forward
                i++;
            }
        }

        return ans;
    }
};