class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        adj.reserve(n);

        for(auto i :edges){
            int u=i[0];
            int v=i[1];
            int w =i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<int> dist(n,1e9);

        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(u==n-1) return d;
            if(d!=dist[u]) continue;

            for(auto [v,w]:adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1; //if not possible
    }
};