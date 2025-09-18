class TaskManager {
public:
    unordered_map<int,int> taskPriority;  // taskId -> Priority
    unordered_map<int,int> taskUser; // taskid -> userId
    priority_queue<pair<int,int>> pq;  // {priority,taskID}

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            add(it[0],it[1],it[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPriority[taskId]=priority;
        taskUser[taskId]=userId;
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskPriority[taskId]=newPriority; //overwrite the previous entry
        pq.push({newPriority,taskId}); // new entry
    }
    
    void rmv(int taskId) {
        taskPriority[taskId]=-1;  // can't be executed 
    }
    
    int execTop() {

        while(!pq.empty()){
            int priority=pq.top().first;
            int task=pq.top().second;
            
            pq.pop();

            if(priority==taskPriority[task]){  //if the priority found in heap is equal to the priority found in the taskPriority Map
                taskPriority[task]=-1;
                return taskUser[task];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */