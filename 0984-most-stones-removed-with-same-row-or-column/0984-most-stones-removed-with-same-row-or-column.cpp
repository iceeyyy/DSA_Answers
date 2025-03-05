class disjoint_set{
    vector<int> rank,size,par;
    public:
    disjoint_set(int n){
        //creating the disjoint data-structure that involves either rank and parent array or size and parent array.
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par.push_back(i);
        }
    }
    int findpar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=findpar(par[x]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u!=ulp_v){
            if(size[ulp_u]<size[ulp_v]){
                par[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                //ulp_u is greater than ulp_v or equal
                par[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        int cnt=0;
        int n=stones.size();
    for(auto i:stones){
        maxRow=max(maxRow,i[0]);
        maxCol=max(maxCol,i[1]);
    }
    disjoint_set ds(maxRow+maxCol+1);
    unordered_map<int,int> mp;
    for(auto i:stones){
        int row=i[0];
        int col=i[1]+maxRow+1;
        ds.unionBySize(row,col);
        mp[row]=1;
        mp[col]=1;
    }

    for(auto i:mp){
        if(ds.findpar(i.first)==i.first){
            cnt++;
        }
    }
    
    return n-cnt;
    }
};