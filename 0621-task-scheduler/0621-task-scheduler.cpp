class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        for(auto ch:tasks){
            mp[ch-'A']++;
        }
        priority_queue<int>pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        int intervals=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                intervals+=temp.size();
            }
            else{
                intervals+=n+1;
            }
        }
        return intervals;
    }
};