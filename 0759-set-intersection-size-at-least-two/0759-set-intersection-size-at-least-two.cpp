class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto lambda = [](auto &vec1, auto &vec2){
            if(vec1[1]!=vec2[1]) return vec1[1] < vec2[1]; // if last digit is not same then sort in asc order
            return vec1[0] > vec2[0]; //else in desc order 
        };

        sort(intervals.begin(),intervals.end(),lambda);

        int ans=0;
        int first=-1;
        int last=-1;

        for(int i=0;i<intervals.size();i++){
            int L=intervals[i][0];
            int R=intervals[i][1];

            if(L <= first) continue; //entirely overlapping

            if(L > last){
                //no overlapping
                ans+=2;
                first=R-1;
                last=R;
            }

            else{
                //including starting element
                ans+=1;
                first=last;
                last=R;
            }

        }

        return ans;
    }
};