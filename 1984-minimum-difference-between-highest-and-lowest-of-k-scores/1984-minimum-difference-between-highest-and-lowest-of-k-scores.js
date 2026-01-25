/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    nums.sort((a,b)=>a-b);
    let i=0;
    let j=i+k-1;
    let ans=Infinity;

    while(j<nums.length){
        ans=Math.min(ans,nums[j]-nums[i]);
        i++;
        j++;
    }

    return ans;
};