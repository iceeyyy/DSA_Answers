class Solution {
public:
    string converted(int n){
        //returns a sorted string
        string s = to_string(n);
        sort(s.begin(),s.end());

        return s;
    }
    bool reorderedPowerOf2(int n) {
        string ss = converted(n);

        for(int i=0;i<30;i++){
            //check for all powers of 2 
            if(ss==converted(1<<i)) return true;
        }
        
        return false;
    }
};