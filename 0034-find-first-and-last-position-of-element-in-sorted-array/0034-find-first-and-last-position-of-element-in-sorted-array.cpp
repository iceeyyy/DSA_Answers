class Solution {
public:
    int binaryS(vector<int> nums,int target,bool indicator){
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2; // for handling large values
            if(indicator){
                if(nums[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]>target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return indicator ? (l < nums.size() && nums[l] == target ? l : -1) : (r >= 0 && nums[r] == target ? r : -1);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums.size()==0) return {-1,-1};

        int fS=binaryS(nums,target,true);
        int lS=binaryS(nums,target,false);

        return {fS,lS};
    }
};