class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        thread t1([&](){
            sort(players.begin(),players.end());
        });
        //implemented multithreading for sorting for better time complexity
        thread t2([&](){
            sort(trainers.begin(),trainers.end());
        });
        t1.join();
        t2.join();  
        
        int cnt=0;
        int i=0;
        int j=0;

        while(i<players.size() && j<trainers.size()){

            if(players[i]<=trainers[j]){
                cnt++;
                i++;  
                j++;
            }
            else{
                j++; //trainer can't be accomodated
            }
        }

        return cnt;
    }
};