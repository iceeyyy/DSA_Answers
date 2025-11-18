class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt1=0;
        int n=bits.size();

        for(int i=n-2;i>=0;i--){
            if(bits[i]==1) cnt1++;
            else{
                break;
            }
        }

        return (cnt1&1)?false:true;
    }
};