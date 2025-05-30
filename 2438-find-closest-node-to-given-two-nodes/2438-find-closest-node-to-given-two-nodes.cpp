class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> dist(n,vector<int> (2,-1));

        queue<pair<int,int>> q;
        q.push({node1,0});
        q.push({node2,1});

        dist[node1][0]=0;
        dist[node2][1]=0;

        while(!q.empty()){
            auto nodes = q.front();
            int node = nodes.first;
            int nodeNo = nodes.second;
            q.pop();
            //BFS with multiple nodes
            if(edges[node]!=-1 && dist[edges[node]][nodeNo]==-1){
                dist[edges[node]][nodeNo] = 1 + dist[node][nodeNo];
                q.push({edges[node],nodeNo});
            }
        }

        int maxDist=INT_MAX;
        int reqNode = INT_MAX;

        for(int i=0;i<n;i++){
            
            if(dist[i][0]!=-1 && dist[i][1]!=-1){
                //nodes must be reachable
                if(maxDist>max(dist[i][0],dist[i][1])){
                    maxDist = max(dist[i][0],dist[i][1]);
                    reqNode = i;
                }
            }
            
        }
        
        return (maxDist==INT_MAX)?-1:reqNode;
        
    }
};