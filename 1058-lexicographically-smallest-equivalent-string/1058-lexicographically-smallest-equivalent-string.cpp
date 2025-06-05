class Solution {
public:
    int findPar(vector<int>& dsu,int x){
        if(dsu[x] == -1) return x;

        return dsu[x]=findPar(dsu,dsu[x]);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<int> dsu(26,-1);
        int n=s1.length();

        for(int i=0;i<n;i++){
            int p1=findPar(dsu,s1[i]-'a');
            int p2=findPar(dsu,s2[i]-'a');

            if(p1==p2) continue;

            else{
                if(p1<p2){
                    dsu[p2]=p1;
                }
                else{
                    dsu[p1]=p2;
                }
            }
        }
        string ans="";

        for(int i=0;i<baseStr.length();i++){
            int c = findPar(dsu,baseStr[i]-'a');
            ans+= c +'a';
        }

        return ans;

    }
};