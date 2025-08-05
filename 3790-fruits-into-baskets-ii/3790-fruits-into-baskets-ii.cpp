class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i] && st.find(j)==st.end()){ //must not be present in the set
                    st.insert(j);
                    break;
                }
            }
        }

        return fruits.size()-st.size();
    }
};