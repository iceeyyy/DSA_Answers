class Solution {
public:
    int solve(int i,int j,string& word1, string& word2,vector<vector<int>>& dp){
        //Base case1
        if(i>=word1.length()){
            //it means minimum operations required to convert a empty string to a string of word2.length() - j
            return word2.length()-j;
        }
        // Base case 2
        if(j>=word2.length()){
            //it means minimum operation requird to convert a string of length word1.length()-i to an empty string
            return word1.length()-i;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }

        int insertion=1+solve(i,j+1,word1,word2,dp);

        int deletion=1+solve(i+1,j,word1,word2,dp);

        int replace = 1+solve(i+1,j+1,word1,word2,dp);

        return dp[i][j]=min({insertion,deletion,replace});

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return solve(0,0,word1,word2,dp);

    }
};