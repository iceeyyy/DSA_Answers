class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;
        int n=basket1.size();
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            mp[basket1[i]]++;
            mini=min(mini,basket1[i]);
        }
        for(int i=0;i<n;i++){
            mp[basket2[i]]--;
            mini=min(mini,basket2[i]);
        }

        vector<int> extra;
        for (auto& [num, count] : mp) { 
            if (count % 2 != 0) return -1; // Not possible to balance
            // Add half of the extra elements to be swapped
            for (int i = 1; i <= abs(count) / 2; i++) {
                extra.push_back(num);
            }
        }

        sort(extra.begin(),extra.end());
        long long ans=0;

        for(int i=0;i<extra.size()/2;i++){
            ans+=min(extra[i],mini*2);
        }

        return ans;

    }
};