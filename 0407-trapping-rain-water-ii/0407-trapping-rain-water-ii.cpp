class Solution {
    #define pi pair<int,pair<int,int>> 
public:
    bool isValid(int& x ,int& y ,int& n ,int& m){
        return x>0 && x<n && y>0 && y<m;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<vector<int>> vis (n, vector<int> (m,0));

        //step-1 push all boudnary cells
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heightMap[i][j],{i,j}});    //{height,{i,j}}
                    vis[i][j]=1;
                }
            }
        }
        int lvl=0;
        int trapped_water=0;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();

            int height=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            lvl=max(lvl,height);

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(isValid(nx,ny,n,m) && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    pq.push({heightMap[nx][ny],{nx,ny}});

                    if(heightMap[nx][ny] < lvl){
                        trapped_water += lvl-heightMap[nx][ny];
                    }
                }
            }
        }
        return trapped_water;
    }
};