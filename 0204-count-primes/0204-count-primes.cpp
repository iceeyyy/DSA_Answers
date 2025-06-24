class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int> arr(n,1);
        arr[0]=arr[1]=0;

        for(int i=2;i*i<n;i++){
            if(arr[i]==1){
                for(int j=i*i;j<n;j+=i){
                    arr[j]=0; // all possible multiples should be 0
                }
            }
        }

        int cnt=0; //for counting number of primes

        for(int i=2;i<n;i++){

            if(arr[i]==1){
                cnt++;
            }
            
        }
        return cnt;
    }
};