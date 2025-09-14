class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int maxx=-1;

        vector<bool> ans;

        for(int i=0;i<n;i++){
            maxx=max(maxx,candies[i]);
        }

        for(int i=0;i<n;i++){
            int extra=candies[i]+extraCandies;
            if(extra>=maxx) ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};