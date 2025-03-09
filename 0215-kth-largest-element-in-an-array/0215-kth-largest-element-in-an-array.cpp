class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //stores greater elements at top
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(k!=0){
            ans=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};