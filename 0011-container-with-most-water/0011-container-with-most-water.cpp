class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;

        int maxWater=INT_MIN;

        while(l<r){
            int Wat=0;

            if(height[l]<height[r]){
                //max water would be area of rectangle
                Wat=height[l]*abs(r-l);
                l++;
            }

            else {
                Wat=height[r]*abs(l-r);
                r--;
            }
            maxWater=max(maxWater,Wat);
        }
        return maxWater;
    }
};