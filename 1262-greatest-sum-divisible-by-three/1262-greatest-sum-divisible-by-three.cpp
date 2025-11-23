class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int> rem1;
        vector<int> rem2;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]%3==1) rem1.push_back(nums[i]); //store elements with %3 = 1
            else if (nums[i]%3==2) rem2.push_back(nums[i]); // elements with %3 = 2
        }

        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());

        if(sum%3==0) return sum;

        int ans=0;
        int rem = sum % 3;

        if(rem == 1){
            int remove1 = (rem1.size()>=1)?rem1[0]:INT_MAX;
            int remove2 = (rem2.size()>=2)?rem2[0]+rem2[1]:INT_MAX;
            ans=max(ans,sum-min(remove1,remove2));
        }
        else{
            int remove1 = (rem2.size()>=1)?rem2[0]:INT_MAX;
            int remove2 = (rem1.size()>=2)?rem1[0]+rem1[1]:INT_MAX;
            ans=max(ans,sum-min(remove1,remove2));
        }

        return ans;
    }
};