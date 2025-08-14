class Solution {
public:
    string largestGoodInteger(string num) {
        string ans ="";

        if(num.length()==3 && num[0]==num[1] && num[1]==num[2] ) return num;

        for(int i=0;i<=num.length()-3;i++){
            string cur="";
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                cur=num.substr(i,3);
            }
            if(cur>ans){
                ans=cur;
            }
        }
        return ans;
    }
};