class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;

        for(int i=0;i<words.size();i++){

            for(auto it: words[i]){
                if(it==x){
                    ans.push_back(i);
                    break;
                    //break the loop when one char is found
                }
            }
        }
        return ans;
    }
};