class Solution {
public:
    static bool comp(string &s1,string &s2){
        //comparater function for sorting strings according to their lengths
        return s1.length()<s2.length();
    }
    bool check(string &s1,string &s2){
        //if it is possible string will increase by one
        if(s1.length()!=s2.length()+1) return false;

        int i=0;
        int j=0;

        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                //we need to move the pointer that points to the larger string
                i++;
            }
        }
        if(i==s1.length() && j==s2.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {

        int n=words.size();
        vector<int> dp(n,1);
        int maxi=INT_MIN;
        //sorting strings on the basis of length of the strings
        sort(words.begin(),words.end(),comp);

        //if we sort the input array the problem is converted into longest Divisible Subset 
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){

                if(check(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }

            }
            //for storing the lastIndex
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};