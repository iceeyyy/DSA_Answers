class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> prefix(n);
        vector<int> pos(n);

        for(int i=0;i<n;i++){
            pos[i]=fruits[i][0];
            prefix[i] = fruits[i][1] + ((i==0)?0:prefix[i-1]);
        }

        int maxFruits=0;

        for(int d=0;d<=k/2;d++){
            int remain=k-2*d;
            int i=startPos-d;
            int j=startPos+remain;

            int left=lower_bound(begin(pos),end(pos),i)-begin(pos);
            int right=upper_bound(begin(pos),end(pos),j)-begin(pos)-1;

            if(left<=right){
                int total=prefix[right]-(left>0?prefix[left-1]:0);
                maxFruits=max(maxFruits,total);
            }

            i=startPos-remain;
            j=startPos+d;

            left=lower_bound(begin(pos),end(pos),i)-begin(pos);
            right=upper_bound(begin(pos),end(pos),j)-begin(pos)-1;

            if(left<=right){
                int total=prefix[right]-(left>0?prefix[left-1]:0);
                maxFruits=max(maxFruits,total);
            }
            
        }

        return maxFruits;
    }
};