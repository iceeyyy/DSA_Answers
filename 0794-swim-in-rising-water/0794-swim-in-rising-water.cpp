class Solution {
public:
    bool dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid,int t,int dx[],int dy[]){
        int n=grid.size();
        if(i<0 || i>=n || j<0 ||  j>=n || grid[i][j] > t || vis[i][j]==true) return false; // out of bonds

        if(i==n-1 && j==n-1) return true; // last cell reached

        vis[i][j]=true;

        for(int k=0;k<4;k++){
            int nx=i+dx[k];  //bug no:1
            int ny=j+dy[k];

            if(dfs(nx,ny,vis,grid,t,dx,dy)){
                return true;
            }
        }
        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        int l=grid[0][0];
        int r=n*n-1;  //max value of grid[i][j] is n^2-1
        int ans=0;

        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<bool>> vis(n,vector<bool> (n,false));  // visited needs to be reseted after each attempt // bug no :2

            if(dfs(0,0,vis,grid,mid,dx,dy)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};