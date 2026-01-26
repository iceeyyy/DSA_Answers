function minimumAbsDifference(arr: number[]): number[][] {
    arr.sort((a,b)=>a-b);
    let ans:number[][]=[];

    let minDiff=Infinity;
    //calculating minimum differnce
    for(let i=1;i<arr.length;i++){
        minDiff=Math.min(minDiff,arr[i]-arr[i-1]);
    }
    //if diff is equal to minDiff push it in the ans array
    for(let i=1;i<arr.length;i++){
        let diff = arr[i]-arr[i-1];
        if(diff===minDiff){
            ans.push([arr[i-1],arr[i]]);
        }
    }

    return ans;

};