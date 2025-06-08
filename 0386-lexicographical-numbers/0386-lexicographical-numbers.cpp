class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> temp;

        for(int i=1;i<=n;i++){
            string str = to_string(i);
            temp.push_back(str);
        }
        sort(temp.begin(),temp.end());

        vector<int>ans;

        for(int i=0;i<temp.size();i++){
            int dig = stoi(temp[i]);
            ans.push_back(dig);
        }

        return ans;
    }
};