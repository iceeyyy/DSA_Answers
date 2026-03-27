function areSimilar(mat: number[][], k: number): boolean {
    let m=mat.length;
    let n=mat[0].length;

    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(i%2==0){
                if(mat[i][j]!=mat[i][(j-k%n+n)%n]) return false;
            }
            else{
                if(mat[i][j]!=mat[i][(j+k%n)%n]) return false;
            }
        }
    }

    return true;
};