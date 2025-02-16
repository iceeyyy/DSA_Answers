class Solution {
public:
    bool find(vector<int>& res,vector<bool>& used, int pos, int n){
        if(pos==2*n-1) return 1;

        if(res[pos]!=0){
            return find(res,used,pos+1,n);
        }
        for(int i=n;i>=1;i--){
            if(used[i]==true) continue;

            used[i]=true;
            res[pos]=i;
            if(i==1 && find(res,used,pos+1,n)) return 1;
            if(i>1 && ((pos+i)<(2*n-1)) && res[pos+i]==0){
                res[pos+i]=i;
                if(find(res,used,pos+1,n)){
                    return true;
                }
                res[pos+i]=0;
            }
            used[i]=false;
            res[pos]=0;

        }
        return 0;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1,0);
        vector<bool> used(n+1,false);

        find(res,used,0,n);
        return res;
    }
};