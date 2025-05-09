class Solution {
public:
    bool isPowerOfTwo(int n) {
        //using and bitwise operator there must be only one set bit i.e only one one in the binary form of the number
        if(n<=0) return 0;
        return ((n & (n-1))==0); 
        
    }
};