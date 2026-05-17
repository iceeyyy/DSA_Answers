class Solution {
public:
    bool solve(vector<int>& arr,int i){
        if(i>=arr.size() || i<0|| arr[i]<0 ) return false;
        if(arr[i]==0) return true;

        arr[i]*=(-1);
        bool left = solve(arr,i-arr[i]);
        bool right = solve(arr,i+arr[i]);

        return left||right; 
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr,start);
    }
};