class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto i: nums) pq.push(i);
        int cnt=0;

        while(!pq.empty()){
            long long no=pq.top();
            pq.pop();
            if(no>=k) break;

            long long no2= pq.top();
            pq.pop();
            pq.push(2*(min(no,no2))+max(no,no2));

            cnt++;

        }
        return cnt;
    }
};