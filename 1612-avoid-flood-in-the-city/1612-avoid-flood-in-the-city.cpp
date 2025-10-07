class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int> dry;
        unordered_map<int,int> fullLake;
        vector<int> ans(n,1);

        for(int i=0;i<n;i++){
            if(rains[i]==0) dry.insert(i);
            else{
                if(fullLake.count(rains[i])){
                    auto it = dry.upper_bound(fullLake[rains[i]]);
                    if(it==dry.end()){
                        return {};  //lake is flooded
                    }
                    ans[*it]=rains[i];
                    dry.erase(it);
                }
                ans[i]=-1;
                fullLake[rains[i]]=i;
            }
            
        }
        return ans;
    }
};