class Solution {
public:
int mod= 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> res;

        for(int i=0;i<32;i++){
            if(( n & (1<<i)) != 0){
                //creating powers array on the basis of binary rep of n
                powers.push_back(1<<i);
            }
        }

        for(auto q : queries){
            int start = q[0];
            int end = q[1];

            long prod=1;
            for(int j=start;j<=end;j++){
                prod=(prod * powers[j])% mod;
            }
            res.push_back(prod);
        }

        return res;
    }
};