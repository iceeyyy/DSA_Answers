class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int ans=0;
        int PrevMax=0;

        for(int i=0;i<n;i++){
            int curr=neededTime[i];
            if(i>0 && colors[i]!=colors[i-1]){
                PrevMax=0; //color's are different no need to mantain Previous colors max value
            }
            ans+=min(PrevMax,curr);
            PrevMax = max(PrevMax,curr);
        }

        return ans;
    }
};