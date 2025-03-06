class disjoint_set{
    vector<int> rank,size,par;
    public:
    disjoint_set(int n){
        //creating the disjoint data-structure that involves either rank and parent array or size and parent array.
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }
    int findpar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=findpar(par[x]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u!=ulp_v){
            if(size[ulp_u]<size[ulp_v]){
                par[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                //ulp_u is greater than ulp_v or equal
                par[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint_set ds(n+1);
        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j]; // because accounts[i][0] => name  and we want to store mails
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    //if mail is already present it means that user is already present and we need to union the nodes
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        //extracting values from map and creating a vector of vector
        //in this order
        // 0->j1@com,j2@com
        // 1->r2@com,r3@com
        
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findpar(it.second);
            mergedMails[node].push_back(mail);
        }
    
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].size()==0) continue;
            sort(mergedMails[i].begin(),mergedMails[i].end());
            vector<string>temp;
            
            string name=accounts[i][0];
            temp.push_back(name);

            for(auto it:mergedMails[i]){
                //inserting name with mails
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};