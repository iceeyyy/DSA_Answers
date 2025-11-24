/**
 * @param {number[]} nums
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(nums) {
    let ans=[];
    let n=nums.length;
    let mod=0;

    for(let i=0;i<n;i++){
        mod=(mod*2 + nums[i])%5;
        if(mod===0) ans.push(true);
        else{
            ans.push(false);
        }
    }

    return ans;
};