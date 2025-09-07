class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        for(int i=1;i<=n/2;i++){
            ans.push_back(i); //{-i,i}
            ans.push_back(-i);
        }
        if(n&1==1) ans.push_back(0); //if is odd add 0 to it

        return ans;
    }
};