class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;
        for(const auto& p : friendships) {
            auto u = p[0] - 1, v = p[1] - 1;
            bool ok = false;
            for(const auto x : languages[u]) {
                for(const auto y : languages[v]) {
                    if (x == y) { ok = true; break; }
                }
            }
            if (!ok) { need.insert(u); need.insert(v); }
        }
        
        int ans = languages.size() + 1;
        for(int i = 1; i <= n; ++i) {
            int cans = 0;
            for(auto v : need) {
                bool found = false;
                for(auto c : languages[v]) {
                    if (c == i) { found = true; break; }
                }
                if (!found) ++cans;
            }
            ans = min(ans, cans);
        }
        return ans;
    }
};