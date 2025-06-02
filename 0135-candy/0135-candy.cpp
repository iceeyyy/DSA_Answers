class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = 1+candies[i-1];
            }
        }
        
        int total = candies[n-1];

        for(int i=n-1;i>=1;i--){
            if(ratings[i]<ratings[i-1]){
                candies[i-1]=max(candies[i-1],1+candies[i]);
            }
            total+=candies[i-1];
        }
        return total;
    }
};