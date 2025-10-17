class Solution {
public:
    long long solve(long long  i, long long uniqueChars,bool canChange,unordered_map<long long, long long>& mp,int k,string &s){
        long long key = i<<27|(uniqueChars<<1)|(canChange);
        if(mp.count(key)){
            //bit memoization check
            return mp[key];
        }
        if(i>=s.length()) return 0; //base Case

        int Idx=s[i]-'a';
        int uniqueUpdated= uniqueChars|(1<<Idx);
        int uniqueCount=__builtin_popcount(uniqueUpdated);

        long long res;
        if(uniqueCount > k){
            res=1+solve(i+1,1<<Idx,canChange,mp,k,s);
        }
        else{
            res=solve(i+1,uniqueUpdated,canChange,mp,k,s);
        }

        if(canChange){
            for(int newidx=0;newidx<26;newidx++){
                int newSet= uniqueChars | (1<<newidx);
                int newUniqueUpdated=__builtin_popcount(newSet);

                if(newUniqueUpdated>k){
                    res=max(res,1+solve(i+1,1<<newidx,false,mp,k,s));
                }
                else{
                    res=max(res,solve(i+1,newSet,false,mp,k,s));
                }
            }
        }

        return mp[key]=res;

    }
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, long long> mp;
        return solve(0,0,true,mp,k,s)+1;
    }
};