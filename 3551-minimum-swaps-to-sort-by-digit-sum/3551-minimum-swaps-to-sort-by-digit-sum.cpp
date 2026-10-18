class Solution {
public:
    int digitSum(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted(nums);

        auto lambda=[&](int num1,int num2){
            int dSum1=digitSum(num1);
            int dSum2=digitSum(num2);

            if(dSum1!=dSum2){
                return dSum1<dSum2;
            }
            return num1<num2;
        };

        sort(sorted.begin(),sorted.end(),lambda);
        unordered_map<int,int> mp;
        int swaps=0;

        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
            //value -> index
        }

        for(int i=0;i<n;i++){
            int expected=sorted[i];
            int cur=nums[i];

            if(expected == cur) continue;

            int idx=mp[expected];
            //swap
            swap(nums[i],nums[idx]);

            mp[expected]=i;
            mp[cur]=idx;
            swaps++;

        }

        return swaps;
        
    }
};