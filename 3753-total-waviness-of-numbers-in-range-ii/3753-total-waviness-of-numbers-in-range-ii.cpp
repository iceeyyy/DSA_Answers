class Solution {
public:
    typedef long long ll;
    string s;
    int n;
    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaveScore[16][10][10];
    pair<ll,ll> solve(int cur, int prevPrev,int prev, bool islimitedWithActualNumber,bool isLeadingZero){
        if(cur==n){
            return {1,0}; //no more score can be generated a found 1 number
        }
        if(!islimitedWithActualNumber && !isLeadingZero && prevPrev>=0 && prev>=0){
            if(dpTotalNumbers[cur][prevPrev][prev]!=-1 && dpTotalWaveScore[cur][prevPrev][prev]!=-1){
                return {dpTotalNumbers[cur][prevPrev][prev],dpTotalWaveScore[cur][prevPrev][prev]};
            }
        }
        ll totalNumbers=0;
        ll totalWaveScore=0;

        int limitDigit = islimitedWithActualNumber?(s[cur]-'0'):9;

        for(int digit=0;digit<=limitDigit;digit++){
            bool newIsLeadingZero= isLeadingZero && (digit==0);
            int newPrevPrev=prev;
            int newPrev=newIsLeadingZero?-1:digit;

            auto[remainTotalNumber,remainTotalWaveScore] = solve(cur+1,newPrevPrev,newPrev,islimitedWithActualNumber && (digit==limitDigit),newIsLeadingZero);

            if(!newIsLeadingZero && prevPrev>=0 && prev>=0){
                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if(isPeak || isValley){
                    totalWaveScore+=remainTotalNumber;
                }
            }
            totalNumbers+=remainTotalNumber;
            totalWaveScore+=remainTotalWaveScore;
        }
        if(!islimitedWithActualNumber && !isLeadingZero && prevPrev>=0 && prev>=0){
            
            dpTotalNumbers[cur][prevPrev][prev] = totalNumbers;
            dpTotalWaveScore[cur][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers,totalWaveScore};
    }
    ll func(ll num){
        if(num<100) return 0;
        s=to_string(num);
        n=s.length();

        memset(dpTotalNumbers,-1,sizeof(dpTotalNumbers));
        memset(dpTotalWaveScore,-1,sizeof(dpTotalWaveScore));

        auto [totalNumbers,totalWaveScore] = solve(0,-1,-1,true,true);
        
        return totalWaveScore;
    }
    long long totalWaviness(long long num1, long long num2) {
        return func(num2)-func(num1-1);
    }
};