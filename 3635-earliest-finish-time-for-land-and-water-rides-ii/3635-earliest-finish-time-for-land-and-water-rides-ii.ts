function solve(start1:number[],duration1:number[],start2:number[],duration2:number[]){
    let finish1=Infinity;
    let finish2=Infinity;
    
    for(let i=0;i<start1.length;i++){
        finish1=Math.min(finish1,start1[i]+duration1[i]);
    }
    for(let i=0;i<start2.length;i++){
        finish2=Math.min(finish2,Math.max(finish1,start2[i])+duration2[i]);
    }

    return finish2;
}
function earliestFinishTime(landStartTime: number[], landDuration: number[], waterStartTime: number[], waterDuration: number[]): number {
    let res1=solve(landStartTime,landDuration,waterStartTime,waterDuration); // land=>water
    let res2=solve(waterStartTime,waterDuration,landStartTime,landDuration); // water=>land

    return Math.min(res1,res2);
};