class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();

        vector<long long> finishTime(n,0);

        for(int j=0;j<m;j++){
            finishTime[0] += mana[j]*skill[0];
            for(int i=1;i<n;i++){
                finishTime[i] = max(finishTime[i],finishTime[i-1]) + 1LL* mana[j] * skill[i];
            }
            for(int i=n-1;i>0;i--){
                finishTime[i-1] = finishTime[i] - 1LL* skill[i] * mana[j];
            }
        }

        return finishTime[n-1];
    }
};