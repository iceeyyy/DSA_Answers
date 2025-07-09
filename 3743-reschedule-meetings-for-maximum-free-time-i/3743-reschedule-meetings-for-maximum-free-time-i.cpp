class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]-0); // if meeting starts from anything else instead of 0
        
        int n = startTime.size();

        for(int i=1;i<n;i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]); //if last meeting ends before eventTime

        int i=0;
        int j=0;
        int n1=freeTime.size();
        int ans=0;
        int curSum=0;

        while(j<n1){
            curSum+=freeTime[j];

            if(i<n1 && j-i+1>k+1){
                curSum-=freeTime[i];
                i++;
            }

            ans=max(ans,curSum);
            j++;
        }

        return ans;
    }
};