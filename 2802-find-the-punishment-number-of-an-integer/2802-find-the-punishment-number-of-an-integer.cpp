class Solution {
public:
    bool isValid(string &sq,int pos ,int sum,int val){
        if(pos>=sq.size()){
            return sum==val;
        }
        for(int i=0;i+pos<sq.size();i++){
            int cur_val=stoi(sq.substr(pos,i+1));

            if(isValid(sq,i+pos+1,sum+cur_val,val)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int p_num=1;
        for(int i=2;i<=n;i++){
            string sq=to_string(i*i);
            if(isValid(sq,0,0,i)){
                p_num+=i*i;
            }
        }
        return p_num;
    }
};