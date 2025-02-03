class Solution {
public:
    
    bool isPerfectSquare(int num) {
        if(num<2) return true;
        long long int start=1;
        long long int end=num;
        while(start<=end){
            long long int  mid= start + (end-start)/2;
            long long int sq=mid*mid;
            if(num==sq) return true;
            if(sq<num) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
};