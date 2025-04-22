class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n=str1.size();
        int m=str2.size();
        //creating dp table for longest common subsequence
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        //setting up base cases
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=n;
        int j=m;

        string ans="";

        while( i > 0 && j > 0 ){

         if(str1[i-1]==str2[j-1]){
            //same characters will be inserted once
            ans+=str1[i-1];

            i--;
            j--;
        }
         else if(dp[i-1][j]>dp[i][j-1]){
            //moving upward
            ans+=str1[i-1];
            i--;
        }
         else{
            ans+=str2[j-1];
            j--;
        }
    }

     while(i>0){
        //checking for left charaters from str1
        ans+=str1[i-1];
        i--;
    }

     while(j>0){
        //checking for left charaters from str2
        ans+=str2[j-1];
        j--;
    }
    //we need to reverse the answer because the derived string is in reversed order //we started from bottom
     reverse( ans.begin(),ans.end());

     return ans;

    }

    
};