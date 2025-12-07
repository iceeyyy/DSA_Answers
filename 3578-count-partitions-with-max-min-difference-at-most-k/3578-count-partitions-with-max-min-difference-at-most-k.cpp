class Solution {
public:
    int M = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        vector<int> prefix(n+1,0);

        dp[0]=1;
        prefix[0]=1;

        deque<int> maxD,minD;
        int i=0;
        int j=0;

        while(j<n){
            while(!maxD.empty() &&nums[j] > nums[maxD.back()]){
                maxD.pop_back(); //validating maxD
            }
            maxD.push_back(j);

            while(!minD.empty() && nums[j] < nums[minD.back()]){
                minD.pop_back(); //validating minD
            }
            minD.push_back(j);

            while(i<=j && nums[maxD.front()] - nums[minD.front()]>k){
                i++;

                if(!maxD.empty() && maxD.front() < i){
                    maxD.pop_front(); //removing out of bonds
                }
                if(!minD.empty()&& minD.front() < i){
                    minD.pop_front();
                }
            }

            dp[j+1] = (prefix[j] - ( i>0 ? prefix[i-1]:0)+M) % M;
            prefix[j+1] = (prefix[j] + dp[j+1]) % M;

            j++;
        }
        return dp[n];
    }
};