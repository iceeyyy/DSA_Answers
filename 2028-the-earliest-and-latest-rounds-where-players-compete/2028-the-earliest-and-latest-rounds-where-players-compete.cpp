class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int p1=firstPlayer;
        int p2=secondPlayer;

        if(p1==n-p2+1){
            return{1,1};
        }

        if(p1 > n-p2+1){
            int temp=n-p1+1;
            p1=n-p2+1; //symmetrical shift 
            p2=temp;
        }

        int minRound = n;
        int maxRound = 1;
        int nextPlayers=(n+1)/2;

        if(p2<=nextPlayers){
            int countLeft=p1-1;
            int midcnt=p2-p1-1;

            for(int survLeft=0; survLeft<=countLeft; survLeft++){
                for(int survMid=0; survMid<=midcnt; survMid++){
                    int pos1=survLeft+1;
                    int pos2=pos1+survMid+1;

                    vector<int> temp = earliestAndLatest(nextPlayers,pos1,pos2);

                    minRound=min(minRound,temp[0]+1);
                    maxRound=max(maxRound,temp[1]+1); // +1 for considering the present round
                }
            }
        }
        else{//both on opp halfes
            int fp2=n-p2+1;
            int countLeft=p1-1;
            int midcnt=fp2-p1-1;
            int remMid=p2-fp2-1;

             for(int survLeft=0; survLeft<=countLeft; survLeft++){
                for(int survMid=0; survMid<=midcnt; survMid++){
                    int pos1 =survLeft+1;
                    int pos2=pos1+survMid+(remMid+1)/2 +1;

                    vector<int> temp = earliestAndLatest(nextPlayers,pos1,pos2);

                    minRound=min(minRound,temp[0]+1);
                    maxRound=max(maxRound,temp[1]+1);

                }
             }
        }
        
        return {minRound,maxRound};
    }
};