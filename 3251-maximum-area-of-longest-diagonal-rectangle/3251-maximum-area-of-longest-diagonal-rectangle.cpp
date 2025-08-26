class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        int diag=0; //max-diagonal

        for(auto it:dimensions){
            int l=it[0];
            int b=it[1];

            int diagonal=(l*l+b*b);

            if(diag<diagonal){
                diag=diagonal;
                ans=l*b;
            }
            if(diag==diagonal){
                ans=max(ans,l*b);
            }
        }

        return ans;
    }
};