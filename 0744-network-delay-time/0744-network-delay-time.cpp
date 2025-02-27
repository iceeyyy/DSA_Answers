class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i :times){
            int s=i[0];
            int d=i[1];
            int delay=i[2];
            adj[s].push_back({d,delay});
        }
        vector<int> del(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        del[k]=0;
        //{time,delay,node}
        pq.push({0,k});
        int minTime=0;

        while(!pq.empty()){
            int delay=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int nNode=it.first;
                int deNode=it.second;
                if(del[nNode]>deNode+delay){
                    del[nNode]=deNode+delay;
                    pq.push({del[nNode],nNode});
                }
            }
        }
        //nodes start from 1 
        for(int i=1;i<=n;i++){
            if(del[i]==INT_MAX){
                return -1;
            }
            minTime=max(minTime,del[i]);
        }
        return minTime;
    }
};