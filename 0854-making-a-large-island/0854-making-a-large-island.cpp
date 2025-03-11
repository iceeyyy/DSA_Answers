class disjoint_set{
    public:
    vector<int> rank,size,par;
    
    disjoint_set(int n){
        //creating the disjoint data-structure that involves either rank and parent array or size and parent array.
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }
    int findpar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=findpar(par[x]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u!=ulp_v){
            //smaller rank gets connected to the larger one
            if(rank[ulp_u]<rank[ulp_v]){
                par[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                par[ulp_v]=ulp_u;
            }
            else{
                //ranks of ulp_v and ulp_u are equal
                par[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
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
    bool valid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        disjoint_set ds(n*n);
        //checking four directions
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        //connecting the components that are already one;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int newRow=i+drow[k];
                    int newCol=j+dcol[k];
                    if(grid[i][j]==1 && valid(newRow,newCol,n) && grid[newRow][newCol]==1){
                        //converting cells to nodes
                        int node=i*n+j;
                        int newNode= newRow*n+ newCol;
                        ds.unionBySize(node,newNode);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> components; // for avoiding same parents to be include multiple times
                    for(int k=0;k<4;k++){
                        int newRow=i+drow[k];
                        int newCol=j+dcol[k];
                        if(valid(newRow,newCol,n) &&  grid[newRow][newCol] == 1){
                            int newNode=newRow*n+newCol;
                            components.insert(ds.findpar(newNode));
                        }
                    }
                    int sizeTotal=1; // sizeTotal=1 because it adds the converted 0 to 1
                    for(auto it:components){
                        sizeTotal+=ds.size[it];
                    }
                    ans=max(ans,sizeTotal);
                }    
            }
        }
        //if the grid has all ones
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,ds.size[ds.findpar(i*n+j)]);
            }
        }

        return ans;

    }
};