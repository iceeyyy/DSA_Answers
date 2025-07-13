class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Thread t1=new Thread(()-> Arrays.sort(players));
        Thread t2=new Thread(()-> Arrays.sort(trainers));

        t1.start();
        t2.start();
        try{
            t1.join();
            t2.join();
        }
        catch(InterruptedException e){
            Thread.currentThread().interrupt();
        }
        

        int i=0;
        int j=0;
        int n=players.length;
        int m=trainers.length;
        int cnt=0;

        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
}