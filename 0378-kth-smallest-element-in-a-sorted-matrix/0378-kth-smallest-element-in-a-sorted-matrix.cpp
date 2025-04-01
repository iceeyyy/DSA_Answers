class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq; //min-heap
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                pq.push(matrix[i][j]);
            }
        }
        int ans;
        while(k!=0){
            int ele=pq.top();
            pq.pop();
            ans=ele;
            k--;
        }
        return ans;
    }
};