class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest=INT_MAX;
        for(auto i:nums){
            if(abs(i)<abs(closest)|| (abs(i)==abs(closest) && i>closest)){
                closest=i;
            }
        }
        return closest;
    }
};