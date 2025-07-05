class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        int ans=-1;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        for(auto it:mp){
            if(it.first==it.second){
                ans=it.first;
            }
        }
        
        return ans;
    }
};