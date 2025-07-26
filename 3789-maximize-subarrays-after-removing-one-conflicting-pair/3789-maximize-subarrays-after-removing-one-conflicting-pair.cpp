#define all(x) x.begin(), x.end()      
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid=0;
        long long res=0;

        vector<vector<int>> confPairs(n+1);

        for(auto it:conflictingPairs){
            int u=min(it[0],it[1]);
            int v=max(it[0],it[1]);
            confPairs[v].push_back(u);
        }

        vector<long long> extra(n+1,0);
        int maxConf=0;
        int secondMax=0;
        
        for(int end=1;end<=n;end++){
            
            for(auto i:confPairs[end]){
                if(i>=maxConf){
                    secondMax=maxConf;
                    maxConf=i;
                }
                else if(i>secondMax){
                    secondMax=i;
                }
            }
            valid+=end-maxConf;
            extra[maxConf]+=maxConf-secondMax;
        }

        res = valid + *max_element(all(extra));

        return res;
    }
};