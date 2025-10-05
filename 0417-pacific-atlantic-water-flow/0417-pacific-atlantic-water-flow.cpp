class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& height,int dx[],int dy[]){
        vis[r][c]=1;

        int n=height.size();
        int m=height[0].size();

        for(int i=0;i<4;i++){
            int nx=r+dx[i];
            int ny=c+dy[i];

            if( nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && height[nx][ny] >= height[r][c]){
                dfs(nx,ny,vis,height,dx,dy);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> ans;

        //top,right,bottom,left
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<int>> atlantic(n,vector<int> (m,0));
        vector<vector<int>> pacific(n,vector<int> (m,0));

        //top and left
        for(int i=0;i<n;i++) dfs(i,0,pacific,heights,dx,dy);
        for(int j=0;j<m;j++) dfs(0,j,pacific,heights,dx,dy);

        //right and bottom
        for(int i=0;i<n;i++) dfs(i,m-1,atlantic,heights,dx,dy);
        for(int j=0;j<m;j++) dfs(n-1,j,atlantic,heights,dx,dy);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};