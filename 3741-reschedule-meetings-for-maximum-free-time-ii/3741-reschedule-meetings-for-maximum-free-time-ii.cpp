class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free;
        free.push_back(startTime[0]-0);

        for(int i=1;i<startTime.size();i++){
            free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime.back());

        int n = free.size();

        vector<int> left(n,0);
        vector<int> right(n,0);

        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],free[i+1]);  //right max
        }
        for(int i=1;i<n;i++){ 
            left[i]=max(left[i-1],free[i-1]);   //left max
        }
        int ans=0;

        for(int i=1;i<n;i++){
            int eventDuration = endTime[i-1]-startTime[i-1];

            if(eventDuration <=max(left[i-1],right[i])){  //case-1
                ans=max(ans,eventDuration+ free[i-1]+free[i]);
            }
            ans=max(ans,free[i-1]+free[i]);  //case-2
        }
        return ans;
    }
};