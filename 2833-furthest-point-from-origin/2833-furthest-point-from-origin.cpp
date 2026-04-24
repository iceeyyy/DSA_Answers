class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int blank=0;

        for(auto it:moves){
            if(it=='L') l++;
            else if(it=='R') r++;
            else blank++;
        }

        return abs(r-l)+blank;
    }
};