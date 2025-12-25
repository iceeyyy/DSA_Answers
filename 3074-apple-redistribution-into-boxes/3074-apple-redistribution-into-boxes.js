/**
 * @param {number[]} apple
 * @param {number[]} capacity
 * @return {number}
 */
var minimumBoxes = function(apple, capacity) {
    let ans=0;
    let sum=0;
    let cap=0;

    for(let a of apple){
        sum+=a;
    }
    capacity.sort((a,b)=>a-b);

    for(let i=capacity.length-1;i>=0;i--){
        cap+=capacity[i];
        if(cap>=sum) return capacity.length-i ;
    }

    return -1;

};