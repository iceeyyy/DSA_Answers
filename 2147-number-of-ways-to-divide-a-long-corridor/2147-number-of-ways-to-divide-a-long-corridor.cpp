class Solution {
public:
    int M = 1e9+7;
    int numberOfWays(string corridor) {
        vector<int> seats;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S') seats.push_back(i);
        }

        if(seats.size()%2!=0 || seats.size()==0) return 0;
        
        long long result=1;
        int end_idx = seats[1];

        for(int i=2;i<seats.size();i+=2){
            int length=seats[i] - end_idx;
            result=(result*length)%M;
            end_idx=seats[i+1];
        }

        return result;
    }
};