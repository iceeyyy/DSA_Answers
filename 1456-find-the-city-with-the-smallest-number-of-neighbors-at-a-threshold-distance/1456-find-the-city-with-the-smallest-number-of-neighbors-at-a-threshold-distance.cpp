class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int> (n,INT_MAX));

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]==INT_MAX || cost[k][j]==INT_MAX){
                        continue;
                    }
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }

        int cntCity=n;
        int cityNo=-1;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cntCity){
                cntCity=cnt;
                cityNo=i;
            }
        }
        return cityNo;
    }
};