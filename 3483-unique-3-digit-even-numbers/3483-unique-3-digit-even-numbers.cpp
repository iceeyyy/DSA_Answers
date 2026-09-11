class Solution {
public:
    void help(vector<int>& digits, int &ans, vector<int>& temp, vector<int>& vis){
        
        if(temp.size() == 3){
            if(temp[2] % 2 == 0 && temp[0] != 0){
                ans++;
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++){
            
            if(vis[i]) continue;

            if(i > 0 && digits[i] == digits[i-1] && !vis[i-1])
                continue;

            if(temp.size() == 0 && digits[i] == 0)
                continue;

            vis[i] = 1;
            temp.push_back(digits[i]);

            help(digits, ans, temp, vis);
            temp.pop_back();
            vis[i] = 0;
        }
    }

    int totalNumbers(vector<int>& digits) {
        
        sort(digits.begin(), digits.end());

        vector<int> vis(digits.size(), 0);
        vector<int> temp;

        int ans = 0;

        help(digits, ans, temp, vis);

        return ans;
    }
};