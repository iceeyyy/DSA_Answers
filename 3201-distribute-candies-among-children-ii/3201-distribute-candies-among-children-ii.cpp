class Solution {
public:
    long long comb(int n){
        //for calculating factorial
        if(n<0){
            return 0;
        }
        return (long long)(n+2) * (n+1)/2;
    }
    long long distributeCandies(int n, int limit) {
        long long total = comb(n);

        long long oneChildGotMore = 3*(comb(n-(limit+1)));
        long long twoChildGotMore = 3*(comb(n-2*(limit+1)));
        long long threeChildGotMore = comb(n-3*(limit+1));

        long long invalid = oneChildGotMore-twoChildGotMore +threeChildGotMore;
        long long ans = total-invalid;
        return ans;

    }
};