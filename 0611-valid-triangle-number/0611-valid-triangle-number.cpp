class Solution {
public:
    int binarySearch(int high ,int low ,int target,vector<int>& nums){
        int k=-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]<target){
                k=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){  //O(n)2
            if(nums[i]==0) continue;
            for(int j=i+1;j<n;j++){

                int sum=nums[i]+nums[j];

                int mid=binarySearch(n-1,j+1,sum,nums); // logn

                if(mid!=-1){
                    count+=mid-j;
                }

            }
        }
        return count; 
    }
};