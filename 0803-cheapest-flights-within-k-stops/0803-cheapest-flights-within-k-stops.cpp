class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        //creating adjlist
        for(auto i:flights){
            int from=i[0];
            int to=i[1];
            int pric=i[2];
            adj[from].push_back({to,pric});
            
        }
        vector<int> price(n,INT_MAX);
        price[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //{stops,{price,node}}
        pq.push({0,{0,src}});

        while(!pq.empty()){
            int Stops=pq.top().first;
            int pricee=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
           
            if( Stops> k){
                continue;
            }
            
            for(auto it:adj[node]){
                int newNode=it.first;
                int Cost=it.second;
                if(price[newNode]>pricee+Cost){
                    price[newNode]=pricee+Cost;
                    pq.push({Stops+1, {pricee + Cost, newNode}});

                }
            }
        }
        return (price[dst]==INT_MAX)?-1:price[dst];
    }
};