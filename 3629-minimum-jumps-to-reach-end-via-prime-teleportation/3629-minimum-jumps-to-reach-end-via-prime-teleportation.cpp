class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);

        if(n >= 0) isPrime[0] = false;
        if(n >= 1) isPrime[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int maxEl=nums[0];

        int steps=0;
        
        unordered_map<int,vector<int>> mp;
        unordered_set<int> st;


        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxEl=max(maxEl,nums[i]);
        }

        vector<bool> isPrime = sieve(maxEl);
        queue<int> q;
        vector<bool> vis(n,false);

        q.push(0);
        vis[0]=true;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front();
                q.pop();
                if(i==n-1) return steps;

                if(i-1>=0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1]=true;
                }
                if(i+1<n && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1]=true;
                }
                // if(!isPrime[nums[i]]) continue;
                if(isPrime[nums[i]] && !st.count(nums[i])){

                    for(int mult=nums[i];mult<=maxEl;mult+=nums[i]){
                        if(!mp.contains(mult)) continue;

                        for(auto j:mp[mult]){
                            if(!vis[j]){
                                q.push(j);
                                vis[j]=true;
                            }
                        }
                    }
                }
                st.insert(nums[i]);
            }
            steps++;
        }

        return steps;

    }
};