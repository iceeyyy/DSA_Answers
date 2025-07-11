class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        vector<int> availcnt(n,0);
        set<int> st;
        priority_queue<pair<long long,long long >,vector<pair<long long ,long long >>,greater<pair<long long ,long long >>> pq;

        int m=meetings.size();

        for(int i=0;i<n;i++){
            st.insert(i);
        }

        for(int i=0;i<m;i++){
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            while(pq.size()>0 && pq.top().first<=start){
                int room = pq.top().second;
                pq.pop();
                st.insert(room);
            }

            if(st.size()==0){
            auto p = pq.top();
            pq.pop();
            long long diff = end-start;
            start = p.first;
            end = start+diff;
            st.insert(p.second);
            }
            auto it = st.begin();
            availcnt[*it]++;
            pq.push({end,*it});
            st.erase(*it);
        }

        int ans=0;
        int maxi=0;

        for(int i=0;i<n;i++){
            if(maxi<availcnt[i]){
                maxi=availcnt[i];
                ans=i;
            }
        }

        return ans;

        
    }
};