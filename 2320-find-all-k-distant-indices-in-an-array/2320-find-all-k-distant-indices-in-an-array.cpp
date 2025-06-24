class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){

            if(nums[i]==key){
                int start=max(0,i-k);
                int end=min(i+k,n-1);

                if(!ans.empty() && ans.back()>=start){
                    //check for overlaping condition
                    start=ans.back()+1;
                }

                for(int j=start;j<=end;j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;

    }
};