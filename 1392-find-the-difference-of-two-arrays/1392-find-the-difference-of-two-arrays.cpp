class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(),nums1.end());
        unordered_set<int> st2(nums2.begin(),nums2.end());

        vector<int> ans1,ans2;

        for(auto num:st1){
            if(st2.find(num)==st2.end()){
                ans1.push_back(num); // it means it is present in nums1 but not in nums2
            }
        }

        for(auto num:st2){
            if(st1.find(num)==st1.end()){
                ans2.push_back(num); // it means it is present in nums1 but not in nums2
            }
        }
        
        return {ans1,ans2};
    }
};