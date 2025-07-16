class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int pos=0;
        int even=0;
        int odd=0;
        //check for longest possible parity even or odd
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) odd++;
            else{
                even++;
            }
        }
        pos=max(even,odd);

        int len=1;
        int cur=nums[0]%2;

        for(int i=1;i<nums.size();i++){
            if(nums[i]%2!=cur){
                cur=nums[i]%2; //change the cur because we want the next element to be of opposite parity
                len++;
            }
        }
        return max(len,pos);
    }
};