/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    let n=strs.length;
    let m=strs[0].length; 
    let cnt=0;

    for(let col=0;col<m;col++){
        for(let row=1;row<n;row++){
            if(strs[row][col]<strs[row-1][col]){
                cnt++;
                break;
            }
        }
    }

    return cnt; 
};