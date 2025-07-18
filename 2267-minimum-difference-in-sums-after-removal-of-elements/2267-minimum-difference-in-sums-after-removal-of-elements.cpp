class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;

        vector<long long> leftMin(N,0);
        priority_queue<long long>pq; //max-heap

        long long leftSum=0;
        for(int i=0;i<2*n;i++){
            pq.push(nums[i]);
            leftSum+=nums[i];
            if(pq.size()>n){
                leftSum-=pq.top();
                pq.pop();
            }
            leftMin[i]=leftSum;
        }
        vector<long long> rightMax(N,0);
        priority_queue<long long,vector<long long>,greater<long long>> pqmin;

        long long rightSum=0;
        for(int i=N-1;i>=n;i--){
            pqmin.push(nums[i]);
            rightSum+=nums[i];
            if(pqmin.size()>n){
                rightSum-=pqmin.top();
                pqmin.pop();
            }
            rightMax[i]=rightSum;
        }

        long long ans=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            ans=min(ans,leftMin[i]-rightMax[i+1]);
        }
        return ans;
    }
};