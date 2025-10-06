class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //{maxx,{r,c}}
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int step=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;

            if(x==n-1 && y==n-1) return step;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    int maxx = max(grid[nx][ny],step);
                    vis[nx][ny]=1;
                    pq.push({maxx,{nx,ny}});
                }
            }

        }

        return -1;
    }
};