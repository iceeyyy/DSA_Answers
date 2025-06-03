class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        int ans = 0;
        unordered_set<int> st;


        queue<int> q;

        for(auto start:initialBoxes){
            q.push(start);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            //if box is closed add it to the set
            if(status[cur]==0){
                st.insert(cur);
                continue;
            }
            //if keys are present erase the box number from set and push it to the queue for traversal
            for(auto i:keys[cur]){
                status[i]=1;
                if(st.count(i)){
                    q.push(i);
                    st.erase(i);
                }
            }
            //add 
            ans+=candies[cur];

            for(auto it:containedBoxes[cur]){
                q.push(it);
            }

        }
        return ans;
    }
};