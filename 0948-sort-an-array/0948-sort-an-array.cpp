class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //using a min-heap for sorting 
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());

        vector<int> ans;
        while(!pq.empty()){
            //push the smallest element the answer vector
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};