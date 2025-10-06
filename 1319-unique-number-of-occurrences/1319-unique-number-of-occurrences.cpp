class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto it:mp){
            int freq=it.second;
            int ele=it.first;
            for(auto i:mp){
                int free=i.second;
                int element=i.first;
                if(ele==element) continue;
                if(freq==free) return false;
            }
        }
        
        return true;
    }
};