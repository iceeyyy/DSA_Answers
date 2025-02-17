class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();

       vector<vector<int>> vis(n,vector<int>(m,0));
       vector<vector<int>> dist(n,vector<int>(m,0));
       queue<pair<pair<int,int>,int>> q;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
       }

       // top,right,bottom,left
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};

       while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        dist[row][col]=dis;

        for(int i=0;i<4;i++){
            int ncol=col + dcol[i];
            int nrow=row + drow[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
       }

       return dist;
    }
};