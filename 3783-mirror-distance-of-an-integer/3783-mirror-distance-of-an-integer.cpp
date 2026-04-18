class Solution {
public:
    int mirrorDistance(int n) {
        string rev=to_string(n);
        reverse(rev.begin(),rev.end());
        int num=stoi(rev);
        return(abs(n-num));
    }
};