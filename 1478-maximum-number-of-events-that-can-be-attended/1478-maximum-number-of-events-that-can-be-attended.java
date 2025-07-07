class Solution {
    public int maxEvents(int[][] events) {

        Arrays.sort(events,(a,b)->Integer.compare(a[0],b[0]));

        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(); 
        int pos=0;
        int time=1;
        int cnt=0;
        int n=events.length;

        while(pos<n || !minHeap.isEmpty()){

            if(minHeap.isEmpty()){ 
                //time skip to cover missed time waiting for a event
                time=Math.max(time,events[pos][0]);
            }

            while(pos<n && events[pos][0]==time){
                minHeap.add(events[pos][1]);
                pos++;
            }

            while(!minHeap.isEmpty()&& minHeap.peek()<time){
                //pop the expired elements after comparing with the current time
                minHeap.poll();
            }
            if(!minHeap.isEmpty()){
                minHeap.poll(); //pop the valid element only poping one because we can visit only one event at a time
                cnt++;
            }
            time++;
        }
        return cnt;

    }
}