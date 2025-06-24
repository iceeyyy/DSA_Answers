class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<bool> vis(n,0);

        for(int i=0;i<n;i++){
            //marking index of key
            if(nums[i]==key){
                vis[i]=1;
            }
        }

        set<int> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[j]){
                    if(abs(j-i)<=k){
                        ans.insert(i);
                    }
                }
            }
        }
        vector<int> result(ans.begin(),ans.end());
        return result;
    }
};