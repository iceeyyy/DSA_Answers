class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> pairs;

        for(int i=0;i<arr.size();i++){
            int count= __builtin_popcount(arr[i]);
            pairs.push_back({count,arr[i]});
        }

        sort(pairs.begin(),pairs.end());

        vector<int> ans;

        for(int i=0;i<pairs.size();i++){
            ans.push_back(pairs[i].second);
        }

        return ans;

    }
};