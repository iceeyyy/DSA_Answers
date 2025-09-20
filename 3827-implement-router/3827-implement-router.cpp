class Router {
public:
    int MAX_SIZE;  
    unordered_map<string,vector<int>> packetStore; //key -> {s,d,t}
    unordered_map<int,vector<int>> destTime; // D -> {t1,t2}
    queue<string> q; 

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    string makeKey(int s ,int d ,int t){
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source,destination,timestamp);

        if(packetStore.find(key)!=packetStore.end()){
            return false;
        }

        if(q.size()>=MAX_SIZE){
            forwardPacket();
        }

        packetStore[key]={source,destination,timestamp};
        q.push(key);
        destTime[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetStore.empty()){
            return {};
        }

        string key = q.front();
        q.pop();
        
        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int D = packet[1];
        destTime[D].erase(destTime[D].begin());  // removed from destTime map as well 

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTime.find(destination);

        if(it==destTime.end() || it->second.empty()) return 0;

        vector<int>& timeStamps = it->second;

        int i = lower_bound(timeStamps.begin(),timeStamps.end(),startTime) - timeStamps.begin();
        int j = upper_bound(timeStamps.begin(),timeStamps.end(),endTime) - timeStamps.begin();
        //binay search 

        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */