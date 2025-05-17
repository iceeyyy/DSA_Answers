class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n=arr.size();
        if(n<3) return 0;

        int i=1;

        //ascend
        while(i<n && arr[i]>arr[i-1]){
            i++;
        }
        //it means there is only increasing or decreasing elements
        if(i==1||i==n){
            return false;
        }
        //decent
        while(i<n && arr[i]<arr[i-1]){
            i++;
        }

        return i==n;

    }
};