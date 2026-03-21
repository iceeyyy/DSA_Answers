function reverseSubmatrix(grid: number[][], x: number, y: number, k: number): number[][] {
    let endRow=x+k-1;
    let endCol=y+k-1;

    for(let i=x;i<=endRow;i++){
        for(let j=y;j<=endCol;j++){
            [grid[i][j],grid[endRow][j]] = [grid[endRow][j],grid[i][j]];
        }
        endRow--;
    }

    return grid;
};