function largestSubmatrix(mat: number[][]): number {
    let n = mat.length;
    let m = mat[0].length;
    let maxArea=0;

    let prev:number[] = Array.from({length:m},()=>0);

    for(let i=0;i<n;i++){
        let curRow:number[] = mat[i];
        for(let j=0;j<m;j++){
            if(curRow[j]===1){
                curRow[j]+=prev[j];
            }
        }
        let heights:number[] = curRow;
        heights.sort((a,b)=>b-a); //sorting in descending order

        for(let k=0;k<m;k++){
            let base = k+1;
            let height = heights[k];
            maxArea = Math.max(maxArea,height*base)
        }
        prev=curRow;
    }

    return maxArea;
};