class Solution {
public:
    int mod=1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;

        for(auto point:points){
            int y=point[1];
            mp[y]++;
        }

        long long ans=0;
        long long prevHorizontalLines=0;

        for(auto it:mp){
            int count = it.second;
            long long horizontalLines = (long long)count * (count-1)/2;
            ans+= prevHorizontalLines * horizontalLines;
            
            prevHorizontalLines += horizontalLines;
        }

        return ans % mod;
    }
};