class Solution {
public:
    void heapPush(priority_queue<pair<double,int>>& pq,vector<vector<int>>& classes,int ind){
        double cur_avg = (double)(classes[ind][0])/(classes[ind][1]);
        double new_avg = (double)(classes[ind][0]+1)/(classes[ind][1]+1);
        double avg =new_avg-cur_avg;
        pq.push({avg,ind});
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        int n=classes.size();

        for(int i=0;i<n;i++){
            heapPush(pq,classes,i);
        }
        while(extraStudents--){
            auto cur=pq.top();
            pq.pop();
            //+1
            int index=cur.second;
            classes[index][0]++;
            classes[index][1]++;
            heapPush(pq,classes,index);
        }

        double avg=0.0;
        for(int i=0;i<n;i++){
            avg+=(double)(classes[i][0])/(classes[i][1]);
        }

        return avg/n;
    }
};