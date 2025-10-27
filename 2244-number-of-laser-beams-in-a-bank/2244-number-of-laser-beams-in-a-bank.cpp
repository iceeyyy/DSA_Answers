class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int cnt=0;
        int prev=0;

        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1') cur++;
            }
            if(cur>0){
                cnt+=prev*cur;
                prev=cur;
            }
        }

        return cnt;
    }
};