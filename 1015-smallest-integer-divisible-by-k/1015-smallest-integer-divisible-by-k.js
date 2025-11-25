/**
 * @param {number} k
 * @return {number}
 */
var smallestRepunitDivByK = function(k) {
    if(k==1) return 1;
    let num=0;
    
    for(let l=1;l<=k;l++){
        num=(num*10+1) % k;
        if(num==0) return l;
    }

    return -1;
};