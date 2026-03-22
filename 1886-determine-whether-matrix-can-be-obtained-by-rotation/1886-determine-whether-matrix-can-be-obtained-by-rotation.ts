function findRotation(mat: number[][], target: number[][]): boolean {
    let n = mat.length;
    let m = mat[0].length;

    let one = true;
    let two = true;
    let three = true;
    let four = true;

    for(let i=0;i<n;i++){
        for(let j=0;j<m;j++){

            if(mat[i][j]!=target[j][n-i-1]){
                one=false;
            }
            if(mat[i][j]!==target[m-i-1][n-j-1]){
                two=false;
            }
            if(mat[i][j]!==target[n-j-1][i]){
                three=false;
            }
            if(mat[i][j]!==target[i][j]){
                four = false;
            }
        }
    }

    return one||two||three||four;
};