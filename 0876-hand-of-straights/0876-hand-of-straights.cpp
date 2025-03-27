class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        map<int,int> mp; //for storing freq in a sorted manner
        for(auto it :hand) mp[it]++;

        for(auto i:mp){
            int ele=i.first;
            int freq=i.second;
            if(freq==0) continue;
            for(int j=ele;j<ele+groupSize;j++){
                if(mp[j]==0 || mp[j]<freq) return false;
                mp[j]-=freq;
            }
        }
        return true;
    }
};