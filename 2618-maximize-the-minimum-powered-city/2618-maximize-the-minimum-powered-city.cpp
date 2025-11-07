class Solution {
public:
    bool check(long long mid,vector<long long> & diff,int r,int k ,int n){
        vector<long long> temp=diff;
        long long cumSum=0;

        for(int i=0;i<n;i++){
            cumSum+=temp[i];

            if(cumSum< mid){
                long long need=mid-cumSum;

                if(need > k){
                    return false;
                }

                k-=need;
                cumSum+=need;
                if(i + 2*r + 1 < n){
                    temp[i+2*r+1] -= need;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long> diff(n,0);

        for(int i=0;i<n;i++){
            diff[max(0,i-r)] +=stations[i];

            if(i+r+1<n){
                diff[i+r+1] -= stations[i];
            }

        }

        long long left = *min_element(stations.begin(),stations.end());
        long long right = accumulate(stations.begin(),stations.end(),0LL)+k;
        long long result=0;

        while(left <= right){
            long long mid = left+(right-left)/2;

            if(check(mid,diff,r,k,n)){
                result=mid;
                left=mid+1;
            }

            else{
                right=mid-1;
            }

        }

        return result;
    }
};