class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt=0;

        int i=0;
        int j=0;
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

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