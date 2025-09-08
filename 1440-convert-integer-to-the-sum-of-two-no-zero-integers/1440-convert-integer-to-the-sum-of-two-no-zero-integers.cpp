class Solution {
public:
    bool hasZero(int x){
        //checks for zeros int the number
        while(x){
            int digit=x%10;
            if(digit==0) return true;
            x/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n){

        for(int i=1;i<n;i++){
            int b=n-i;
            if(!hasZero(i)&& !hasZero(b)){
                return{i,b};
            }
        }
        return {-1,-1};
    }
};