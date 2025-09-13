class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));  //visited 

        queue<pair<pair<int,int>,int>> q; //{x,y}
        int x=entrance[0];
        int y=entrance[1];
        q.push({{x,y},0});

        vis[x][y]=1; //mark entrance as visited

        //top,right,bottom,left
        int drow[4]= {-1,0,1,0};
        int dcol[4]= {0,1,0,-1};


        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();

            if((row == 0 || col == 0 || row == n-1 || col == m-1) && !(row == x && col == y)){
                return steps; //must be extreme excluding the entrance points
            }

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]=='.' && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return -1;

    }
};