function minAbsDiff(grid: number[][], k: number): number[][] {
    const m=grid.length;
    const n=grid[0].length;
    
    const ans: number[][] = Array.from({ length: m - k + 1 }, () => Array(n - k + 1).fill(0));
    
    for (let i=0;i<m-k+1;i++) {
        for (let j=0;j<n-k+1;j++) {
            const temp: number[] = [];
            for (let g=i;g<i+k;g++) {
                for (let h=j;h<j+k;h++) {
                    temp.push(grid[g][h]);
                }
            }

            temp.sort((a, b) => a - b);

            let minDiff = Infinity;
            
            for (let t=1;t<temp.length;t++) {
                if (temp[t] !== temp[t - 1]) {
                    minDiff = Math.min(minDiff, temp[t] - temp[t - 1]);
                }
            }

            ans[i][j] = minDiff === Infinity ? 0 : minDiff;
        }
    }

    return ans;
};