class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        //storing the frequencies of the charracters
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;

        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            auto cha=pq.top();
            pq.pop();
            char s=cha.second;
            int n=cha.first;
            for(int i=0;i<n;i++){
                ans+=s;
            }
        }
        return ans;
    }
};