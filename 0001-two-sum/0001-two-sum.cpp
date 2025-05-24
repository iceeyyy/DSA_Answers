class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numbersWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numbersWithIndices.push_back({nums[i], i});  //for storing the current index of the nums elements
        }
        sort(numbersWithIndices.begin(),numbersWithIndices.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=numbersWithIndices[left].first + numbersWithIndices[right].first;
            if(sum==target){
                return {numbersWithIndices[left].second,numbersWithIndices[right].second}; 
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {-1,-1};
    }
};