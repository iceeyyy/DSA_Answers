class Solution {
public:
    bool ispalin(int i, int j,string &s){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int minCut(string s) {
        //tabulation approach
        int n=s.length();
        vector<int> dp(n+1,0);
        //we need to subtract 1 because our code performs partitioning for the last character as well and then return 0 
        for(int i=n-1;i>=0;i--){

            int ans=INT_MAX;

           for(int j=i;j<s.length();j++){
            
            // only call for next when temp string is palindrome
            if(ispalin(i,j,s)){
                int cost=1+dp[j+1];
                ans=min(ans,cost);
            }
        }
          dp[i]=ans;
        }
        return dp[0]-1;
    }
};