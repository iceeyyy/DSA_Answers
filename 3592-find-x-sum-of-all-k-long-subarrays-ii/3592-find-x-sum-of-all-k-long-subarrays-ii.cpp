class Solution {
public:
    void insertPair(const pair<int,int>& p,int x,set<pair<int,int>>& mainn,set<pair<int,int>>& sec,long long & sum){
        if(mainn.size() < x || p > *mainn.begin()){
            sum += 1LL * p.first*p.second;
            mainn.insert(p);

            if(mainn.size()>x){
                auto  removeSmall= *mainn.begin();
                sum -= 1LL * removeSmall.first* removeSmall.second;
                mainn.erase(removeSmall);
                sec.insert(removeSmall);
            }
        }
        else{
            sec.insert(p);
        }
    }
    void removeFromSet(const pair<int,int>& p,set<pair<int,int>>& mainn,set<pair<int,int>>& sec,long long & sum){
        if(mainn.find(p) != mainn.end()){
            sum-=1LL*p.first*p.second;
            mainn.erase(p);

            if(!sec.empty()){
                auto Largest=*sec.rbegin();
                sec.erase(Largest);
                mainn.insert(Largest);
                sum += 1LL*Largest.first*Largest.second;
            } 
        }
        else{
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n =nums.size();
        unordered_map<int,int> mp;

        long long sum=0;
        set<pair<int,int>> mainn;
        set<pair<int,int>> sec;

        vector<long long> result;

        int i=0;
        int j=0;
        //Time Comp: O(N * logN)

        while(j<n){
            if(mp[nums[j]] > 0){
                removeFromSet({mp[nums[j]],nums[j]},mainn,sec,sum);
            }
            mp[nums[j]]++;
            insertPair({mp[nums[j]],nums[j]},x,mainn,sec,sum);

            if(j-i+1==k){
                result.push_back(sum);
                removeFromSet({mp[nums[i]],nums[i]},mainn,sec,sum);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                else{
                    insertPair({mp[nums[i]],nums[i]},x,mainn,sec,sum);
                }
                i++;
            }
            j++;
        }

        return result;
    }
};