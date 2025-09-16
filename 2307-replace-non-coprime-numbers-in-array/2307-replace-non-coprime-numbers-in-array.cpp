class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;

        for(auto it:nums){

            while(!result.empty()){

                int prev = result.back();
                int cur = it;
                int GCD = gcd(prev,cur);  // O(log(min(a,b)))

                if(GCD==1) break;
                
                result.pop_back();

                int LCM = prev/GCD*cur;

                it=LCM;
            }

            result.push_back(it);
        }

        return result;
    }
};