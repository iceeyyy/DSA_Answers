class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=nums.size();

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();  //it will only store k elements
            }
        }
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;

        while(!pq.empty()){
            int ele=pq.top().first;
            int ind=pq.top().second;
            pq.pop();   //sort according to index
            pq1.push({ind,ele});
        }

        while(!pq1.empty()){
            int ele=pq1.top().second;
            ans.push_back(ele);
            pq1.pop();
            k--;
        }
        return ans;
    }
};