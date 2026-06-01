function minimumCost(cost: number[]): number {
    cost.sort((a,b)=>b-a);
    let ans=0;

    for(let i=0;i<cost.length;i++){
        if(i%3==2){
            continue;
        }
        ans+=cost[i];
    }

    return ans;
};