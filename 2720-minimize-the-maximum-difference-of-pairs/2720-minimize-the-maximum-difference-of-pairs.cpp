class Solution {
public:
    bool isPossible(vector<int>& nums,int val,int p){
        int count=0;
        int i=1;

        while(i<nums.size()){
            if(nums[i]-nums[i-1]<=val){
                i+=2;
                count++;
            }
            else{
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.back();
        int mid;
        int ans=INT_MAX;

        while(low<=high){
            mid=low+(high-low)/2;

            if(isPossible(nums,mid,p)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};