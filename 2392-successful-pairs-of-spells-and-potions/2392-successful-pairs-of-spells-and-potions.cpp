class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int spell=spells[i];
            //minPotion*spell>=success
            long long minPotion=ceil(1.0*success/spell);

            if(minPotion>success){
                ans[i]=0;
                continue;
            }

            int numberOfPairs= m - (lower_bound(potions.begin(),potions.end(),minPotion) - potions.begin());
            ans[i]=numberOfPairs;
        }

        return ans;
    }
};