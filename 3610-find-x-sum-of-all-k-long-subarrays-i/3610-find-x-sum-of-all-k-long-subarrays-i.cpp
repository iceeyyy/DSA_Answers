class Solution {
public:
    int findTop(unordered_map<int,int>& mp, int x){
        priority_queue<pair<int,int>> pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int sum=0;

        while(!pq.empty() && x!=0){
            sum+=pq.top().first*pq.top().second;
            pq.pop();
            x--; //taking top x elements
        }

        return sum; 
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        
        int i=0;
        int j=0;

        while(j<n){
            mp[nums[j]]++;

            if(j-i+1==k){ // size of window is k 
                ans.push_back(findTop(mp,x));

                mp[nums[i]]--; 
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};